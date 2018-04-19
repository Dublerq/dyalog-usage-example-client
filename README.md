# dyalog-usage-example-client
Example application simulating a work of real program (web backend in this case) written in C++ utilizing Dyalog library features. Part of a university project.

### How to test remote tcp connection
Client/Server implementation depends on the end user requirements. Because of that it has not been written.
Client example is implemented as `SimpleTCPLogSender`. To simulate server netcat might be used. 
Example command would be: `nc -k -l localhost 6000 >> /tmp/log.txt` to listen continously on `127.0.0.1:6000` and save results to `/tmp/log.txt`.
To browse logs use your favorite text viewer/editor.