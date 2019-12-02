FROM gcc

ADD cppunit-1.12.1.tar /cppunit
#ADD MAKE/XSLTTransform_Linux_x64 /XSLTTransform_Linux_x64

WORKDIR /cppunit
RUN dir
WORKDIR /cppunit/cppunit-1.12.1
RUN ./configure
RUN make
RUN make install
ENV LD_LIBRARY_PATH /usr/local/lib
WORKDIR /