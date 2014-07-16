// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "tagService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

#include "tagServiceHandler.h"
#include "table.h"
#include "atomic.h"

#include <iostream>

using namespace std;

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

Table *gTagTid;
Table *gTidTag;
Atomic *gAtomic;

int main(int argc, char **argv) {
    int port;

    if (argc != 5) {
        cout << "Usage: " << argv[0] << " <port> <id_file> <TagTid db path> <TidTag db path>" << endl;
        return 0;
    }

    port = atoi(argv[1]);

    shared_ptr<tagServiceHandler> handler(new tagServiceHandler());
    shared_ptr<TProcessor> processor(new tagServiceProcessor(handler));
    shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
    shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);

    string atomicPath(argv[2]), tagTidPath(argv[3]), tidTagPath(argv[4]);
    string TagTidTable("Tag->Tid"), TidTagTable("Tid->Tag");

    gAtomic = new Atomic(atomicPath);
    if (!gAtomic->Init()) {
        cout << "Atomic Init error" << endl;
        goto free1;
    }

    gTagTid = new Table(TagTidTable, tagTidPath);
    if (gTagTid == NULL) {
        cout << "new Table(Tag->Tid) error" << endl;
        goto free1;
    }
    if (!gTagTid->Open()) {
        cout << "open Table(Tag->Tid) error" << endl;
        goto free2;
    }

    gTidTag = new Table(TidTagTable, tidTagPath);
    if (gTidTag == NULL) {
        cout << "new Table(Tid->Tag) error" << endl;
        goto free2;
    }
    if (!gTidTag->Open()) {
        cout << "open Table(Tid->Tag) error" << endl;
        goto free3;
    }

    server.serve();

free3:
    delete gTidTag;
free2:
    delete gTagTid;
free1:
    delete gAtomic;
    return -1;
}
