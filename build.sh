ROOT=`pwd`

cd $ROOT
mkdir -p _build && cd _build
cmake ..
make -j8
