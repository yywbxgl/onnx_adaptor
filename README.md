onnx operator adaptor， or optimizer


## budild & install

```
mkdir build
cd budild/
cmake ..
make -j

cd ..
g++ main.cpp  build/libonnx.a   build/libonnx_proto.a  /usr/local/lib/libprotobuf.a  -std=c++11 -pthread -I/usr/local/include -I./onnx/  -o  onnx_adaptor
```

## Usage

```
./bin/onnx_adaptor [input_onnx_model]  [output_onnx_model]
```
