# Library Testing ! 

To compile serverTest : 

     g++ -std=c++11 serverTest.cpp ../Networking/Sockets/ListeningSocket.cpp ../Networking/Sockets/BindingSocket.cpp  ../Networking/Sockets/SimpleSocket.cpp ../Networking/Servers/SimpleServer.cpp ../Networking/Servers/TestServer.cpp -lwsock32 -o  serverTest

To run serverTest : 

    ./serverTest.exe

After you run your serverTest.exe you can write 127.0.0.1 on your browser and see the test message from server ! 



------------------------------------------------------------------------------------------------------

To compile socketTest : 

    g++ -std=c++11 socketTest.cpp ../Networking/Sockets/ListeningSocket.cpp ../Networking/Sockets/BindingSocket.cpp  ../Networking/Sockets/SimpleSocket.cpp  -lwsock32 -o  socketTest

To run socketTest : 

    ./socketTest.exe

