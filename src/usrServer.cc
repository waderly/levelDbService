// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "usrService.h"
#include <thrift/protocol/TCompactProtocol.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/concurrency/PosixThreadFactory.h>

#include "usrServiceHandler.h"
#include "table.h"
#include "atomic.h"

#include <iostream>

using namespace std;

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace ::apache::thrift::concurrency;

using boost::shared_ptr;

Table *gUsrUid;
Table *gUidUsr;
Atomic *gAtomic;

int main(int argc, char **argv) {
    int port;

    if (argc != 5) {
        cout << "Usage: " << argv[0] << " <port> <id_file> <UsrUid db path> <UidUsr db path>" << endl;
        return 0;
    }

    port = atoi(argv[1]);

    shared_ptr<usrServiceHandler> handler(new usrServiceHandler());
    shared_ptr<TProcessor> processor(new usrServiceProcessor(handler));
    shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
    shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TCompactProtocolFactory());

    shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager(8);
    shared_ptr<PosixThreadFactory> threadFactory = shared_ptr<PosixThreadFactory>(new PosixThreadFactory());
    threadManager->threadFactory(threadFactory);
    threadManager->start();
    TThreadPoolServer server(processor, serverTransport, transportFactory, protocolFactory, threadManager);

    string atomicPath(argv[2]), usrUidPath(argv[3]), uidUsrPath(argv[4]);
    string UsrUidTable("Usr->Uid"), UidUsrTable("Uid->Usr");

    gAtomic = new Atomic(atomicPath);
    if (!gAtomic->Init()) {
        cout << "Atomic Init error" << endl;
        goto free1;
    }

    gUsrUid = new Table(UsrUidTable, usrUidPath);
    if (gUsrUid == NULL) {
        cout << "new Table(Usr->Uid) error" << endl;
        goto free1;
    }
    if (!gUsrUid->Open()) {
        cout << "open Table(Usr->Uid) error" << endl;
        goto free2;
    }

    gUidUsr = new Table(UidUsrTable, uidUsrPath);
    if (gUidUsr == NULL) {
        cout << "new Table(Uid->Usr) error" << endl;
        goto free2;
    }
    if (!gUidUsr->Open()) {
        cout << "open Table(Uid->Usr) error" << endl;
        goto free3;
    }

    server.serve();

free3:
    delete gUidUsr;
free2:
    delete gUsrUid;
free1:
    delete gAtomic;
    return -1;
}

