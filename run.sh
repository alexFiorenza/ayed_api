LIGHT_BLUE='\033[0;32m'
file_path=$1
NC='\033[0m' # No Color
printf "🪐 ${LIGHT_BLUE}Running c++ code...${NC}\n"
g++ ./src/$file_path.cpp -o ./builds/a.out
./builds/a.out ./src/$file_path.cpp
