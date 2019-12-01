FROM gcc

ADD . /cppunit

WORKDIR /cppunit
RUN dir
RUN tar -xf cppunit-1.12.1.tar
WORKDIR /cppunit/cppunit-1.12.1
RUN ./configure
RUN make
RUN make install
RUN export LD_LIBRARY_PATH=/usr/local/lib
ENV LD_LIBRARY_PATH /usr/local/lib
WORKDIR /