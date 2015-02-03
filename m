g++-4.9 catch.runner.cpp -c -std=c++14 && \
g++-4.9 test.cpp -c -std=c++14 && \
g++-4.9 src.cpp -c -std=c++14 && \
\
g++-4.9 catch.runner.o test.o src.o -std=c++14 -o test.catch && \
test.catch
