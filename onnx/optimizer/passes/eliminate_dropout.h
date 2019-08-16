// ATTENTION: The code in this file is highly EXPERIMENTAL.
// Adventurous users should note that the APIs will probably change.

#pragma once

#include "onnx/optimizer/passes/optimize_pass.h"

namespace ONNX_NAMESPACE { namespace optimization {

struct EliminateDropout final : public OptimizePass {
  explicit EliminateDropout()
    : OptimizePass("eliminate_dropout", API_TYPE::IR) {
  }

//   static bool is_nop_pad(const std::vector<int64_t> & pads) {
//     for (size_t i = 0; i < pads.size(); i++)
//       if (pads[i] > 0)
//         return false;
//     return true;
//   }

  void eliminate_dropout(Graph& graph) 
  {
    for (auto it = graph.begin(); it != graph.end(); ++it) {
      auto* n = *it;
      DescendOnGraphAttributes(n, [this](Graph& g){eliminate_dropout(g);});
      if (n->kind() == kDropout) 
      {
          n->output()->replaceAllUsesWith(n->input());
          it.destroyCurrent();
          continue;
      }
    }
  }

  void optimize(Graph& graph) override {
    eliminate_dropout(graph);
  }
};

}} // namespace ONNX_NAMESPACE::optimization
