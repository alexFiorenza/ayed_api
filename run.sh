LIGHT_BLUE='\033[0;32m'
NC='\033[0m' # No Color
printf "🪐 ${LIGHT_BLUE}Running c++ code...${NC}\n"
g++ ./src/principal.cpp -o ./builds/a.out
./builds/a.out ./src/principal.cpp
