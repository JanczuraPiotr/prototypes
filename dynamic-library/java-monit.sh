    #!/bin/bash

    cd bin

    java -Dcom.sun.management.jmxremote \
          -Dcom.sun.management.jmxremote.port=5854 \
          -Dcom.sun.management.jmxremote.authenticate=false \
          -Dcom.sun.management.jmxremote.ssl=false \
          -Djava.library.path=/home/piotr/Projekty/prototypes/dynamic-library/bin/ \
          -jar app.jar


    cd --