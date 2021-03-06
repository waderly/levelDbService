/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef tagService_H
#define tagService_H

#include <thrift/TDispatchProcessor.h>
#include "kvsys_types.h"



class tagServiceIf {
 public:
  virtual ~tagServiceIf() {}
  virtual void getTag(std::string& _return, const int16_t tid) = 0;
  virtual int16_t getTid(const std::string& tag) = 0;
};

class tagServiceIfFactory {
 public:
  typedef tagServiceIf Handler;

  virtual ~tagServiceIfFactory() {}

  virtual tagServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(tagServiceIf* /* handler */) = 0;
};

class tagServiceIfSingletonFactory : virtual public tagServiceIfFactory {
 public:
  tagServiceIfSingletonFactory(const boost::shared_ptr<tagServiceIf>& iface) : iface_(iface) {}
  virtual ~tagServiceIfSingletonFactory() {}

  virtual tagServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(tagServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<tagServiceIf> iface_;
};

class tagServiceNull : virtual public tagServiceIf {
 public:
  virtual ~tagServiceNull() {}
  void getTag(std::string& /* _return */, const int16_t /* tid */) {
    return;
  }
  int16_t getTid(const std::string& /* tag */) {
    int16_t _return = 0;
    return _return;
  }
};

typedef struct _tagService_getTag_args__isset {
  _tagService_getTag_args__isset() : tid(false) {}
  bool tid;
} _tagService_getTag_args__isset;

class tagService_getTag_args {
 public:

  tagService_getTag_args() : tid(0) {
  }

  virtual ~tagService_getTag_args() throw() {}

  int16_t tid;

  _tagService_getTag_args__isset __isset;

  void __set_tid(const int16_t val) {
    tid = val;
  }

  bool operator == (const tagService_getTag_args & rhs) const
  {
    if (!(tid == rhs.tid))
      return false;
    return true;
  }
  bool operator != (const tagService_getTag_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const tagService_getTag_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class tagService_getTag_pargs {
 public:


  virtual ~tagService_getTag_pargs() throw() {}

  const int16_t* tid;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _tagService_getTag_result__isset {
  _tagService_getTag_result__isset() : success(false) {}
  bool success;
} _tagService_getTag_result__isset;

class tagService_getTag_result {
 public:

  tagService_getTag_result() : success() {
  }

  virtual ~tagService_getTag_result() throw() {}

  std::string success;

  _tagService_getTag_result__isset __isset;

  void __set_success(const std::string& val) {
    success = val;
  }

  bool operator == (const tagService_getTag_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const tagService_getTag_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const tagService_getTag_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _tagService_getTag_presult__isset {
  _tagService_getTag_presult__isset() : success(false) {}
  bool success;
} _tagService_getTag_presult__isset;

class tagService_getTag_presult {
 public:


  virtual ~tagService_getTag_presult() throw() {}

  std::string* success;

  _tagService_getTag_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _tagService_getTid_args__isset {
  _tagService_getTid_args__isset() : tag(false) {}
  bool tag;
} _tagService_getTid_args__isset;

class tagService_getTid_args {
 public:

  tagService_getTid_args() : tag() {
  }

  virtual ~tagService_getTid_args() throw() {}

  std::string tag;

  _tagService_getTid_args__isset __isset;

  void __set_tag(const std::string& val) {
    tag = val;
  }

  bool operator == (const tagService_getTid_args & rhs) const
  {
    if (!(tag == rhs.tag))
      return false;
    return true;
  }
  bool operator != (const tagService_getTid_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const tagService_getTid_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class tagService_getTid_pargs {
 public:


  virtual ~tagService_getTid_pargs() throw() {}

  const std::string* tag;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _tagService_getTid_result__isset {
  _tagService_getTid_result__isset() : success(false) {}
  bool success;
} _tagService_getTid_result__isset;

class tagService_getTid_result {
 public:

  tagService_getTid_result() : success(0) {
  }

  virtual ~tagService_getTid_result() throw() {}

  int16_t success;

  _tagService_getTid_result__isset __isset;

  void __set_success(const int16_t val) {
    success = val;
  }

  bool operator == (const tagService_getTid_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const tagService_getTid_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const tagService_getTid_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _tagService_getTid_presult__isset {
  _tagService_getTid_presult__isset() : success(false) {}
  bool success;
} _tagService_getTid_presult__isset;

class tagService_getTid_presult {
 public:


  virtual ~tagService_getTid_presult() throw() {}

  int16_t* success;

  _tagService_getTid_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class tagServiceClient : virtual public tagServiceIf {
 public:
  tagServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  tagServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void getTag(std::string& _return, const int16_t tid);
  void send_getTag(const int16_t tid);
  void recv_getTag(std::string& _return);
  int16_t getTid(const std::string& tag);
  void send_getTid(const std::string& tag);
  int16_t recv_getTid();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class tagServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<tagServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (tagServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getTag(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getTid(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  tagServiceProcessor(boost::shared_ptr<tagServiceIf> iface) :
    iface_(iface) {
    processMap_["getTag"] = &tagServiceProcessor::process_getTag;
    processMap_["getTid"] = &tagServiceProcessor::process_getTid;
  }

  virtual ~tagServiceProcessor() {}
};

class tagServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  tagServiceProcessorFactory(const ::boost::shared_ptr< tagServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< tagServiceIfFactory > handlerFactory_;
};

class tagServiceMultiface : virtual public tagServiceIf {
 public:
  tagServiceMultiface(std::vector<boost::shared_ptr<tagServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~tagServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<tagServiceIf> > ifaces_;
  tagServiceMultiface() {}
  void add(boost::shared_ptr<tagServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void getTag(std::string& _return, const int16_t tid) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getTag(_return, tid);
    }
    ifaces_[i]->getTag(_return, tid);
    return;
  }

  int16_t getTid(const std::string& tag) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getTid(tag);
    }
    return ifaces_[i]->getTid(tag);
  }

};



#endif
