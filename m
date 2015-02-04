lSTD=c++14
echo test
time g++-4.9 -I./Include -I./ -L/home/klm/Cpp_nauka/StateMachineEngine/ ./Tests/test.cpp -c -std=$lSTD -lcatch.runner -o ./Obj/test.o
echo message
time g++-4.9 -I./Include -L/home/klm/Cpp_nauka/StateMachineEngine/ ./Source/Message.cpp -c -std=$lSTD -lcatch.runner -o ./Obj/Message.o
echo state
time g++-4.9 -I./Include -L/home/klm/Cpp_nauka/StateMachineEngine/ ./Source/State.cpp -c -std=$lSTD -lcatch.runner -o ./Obj/State.o
echo statemachine
time g++-4.9 -I./Include -L/home/klm/Cpp_nauka/StateMachineEngine/ ./Source/StateMachine.cpp -c -std=$lSTD -lcatch.runner -o ./Obj/StateMachine.o
echo linking
time g++-4.9 -I./Include -L/home/klm/Cpp_nauka/StateMachineEngine/ -lcatch.runner ./Obj/test.o ./Obj/Message.o ./Obj/State.o ./Obj/StateMachine.o -std=$lSTD -o test.catch && \
echo testing
test.catch
