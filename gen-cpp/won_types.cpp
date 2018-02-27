/**
 * Autogenerated by Thrift Compiler (0.11.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "won_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace won {


MasterCheckModel::~MasterCheckModel() throw() {
}


void MasterCheckModel::__set_data(const std::vector<std::vector<std::string> > & val) {
  this->data = val;
}

void MasterCheckModel::__set_masters(const std::vector<std::vector<std::string> > & val) {
  this->masters = val;
}

void MasterCheckModel::__set_sys_status(const int64_t val) {
  this->sys_status = val;
}
std::ostream& operator<<(std::ostream& out, const MasterCheckModel& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t MasterCheckModel::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->data.clear();
            uint32_t _size0;
            ::apache::thrift::protocol::TType _etype3;
            xfer += iprot->readListBegin(_etype3, _size0);
            this->data.resize(_size0);
            uint32_t _i4;
            for (_i4 = 0; _i4 < _size0; ++_i4)
            {
              {
                this->data[_i4].clear();
                uint32_t _size5;
                ::apache::thrift::protocol::TType _etype8;
                xfer += iprot->readListBegin(_etype8, _size5);
                this->data[_i4].resize(_size5);
                uint32_t _i9;
                for (_i9 = 0; _i9 < _size5; ++_i9)
                {
                  xfer += iprot->readString(this->data[_i4][_i9]);
                }
                xfer += iprot->readListEnd();
              }
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.data = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->masters.clear();
            uint32_t _size10;
            ::apache::thrift::protocol::TType _etype13;
            xfer += iprot->readListBegin(_etype13, _size10);
            this->masters.resize(_size10);
            uint32_t _i14;
            for (_i14 = 0; _i14 < _size10; ++_i14)
            {
              {
                this->masters[_i14].clear();
                uint32_t _size15;
                ::apache::thrift::protocol::TType _etype18;
                xfer += iprot->readListBegin(_etype18, _size15);
                this->masters[_i14].resize(_size15);
                uint32_t _i19;
                for (_i19 = 0; _i19 < _size15; ++_i19)
                {
                  xfer += iprot->readString(this->masters[_i14][_i19]);
                }
                xfer += iprot->readListEnd();
              }
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.masters = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->sys_status);
          this->__isset.sys_status = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t MasterCheckModel::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("MasterCheckModel");

  xfer += oprot->writeFieldBegin("data", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_LIST, static_cast<uint32_t>(this->data.size()));
    std::vector<std::vector<std::string> > ::const_iterator _iter20;
    for (_iter20 = this->data.begin(); _iter20 != this->data.end(); ++_iter20)
    {
      {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*_iter20).size()));
        std::vector<std::string> ::const_iterator _iter21;
        for (_iter21 = (*_iter20).begin(); _iter21 != (*_iter20).end(); ++_iter21)
        {
          xfer += oprot->writeString((*_iter21));
        }
        xfer += oprot->writeListEnd();
      }
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("masters", ::apache::thrift::protocol::T_LIST, 2);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_LIST, static_cast<uint32_t>(this->masters.size()));
    std::vector<std::vector<std::string> > ::const_iterator _iter22;
    for (_iter22 = this->masters.begin(); _iter22 != this->masters.end(); ++_iter22)
    {
      {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*_iter22).size()));
        std::vector<std::string> ::const_iterator _iter23;
        for (_iter23 = (*_iter22).begin(); _iter23 != (*_iter22).end(); ++_iter23)
        {
          xfer += oprot->writeString((*_iter23));
        }
        xfer += oprot->writeListEnd();
      }
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("sys_status", ::apache::thrift::protocol::T_I64, 3);
  xfer += oprot->writeI64(this->sys_status);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(MasterCheckModel &a, MasterCheckModel &b) {
  using ::std::swap;
  swap(a.data, b.data);
  swap(a.masters, b.masters);
  swap(a.sys_status, b.sys_status);
  swap(a.__isset, b.__isset);
}

MasterCheckModel::MasterCheckModel(const MasterCheckModel& other24) {
  data = other24.data;
  masters = other24.masters;
  sys_status = other24.sys_status;
  __isset = other24.__isset;
}
MasterCheckModel& MasterCheckModel::operator=(const MasterCheckModel& other25) {
  data = other25.data;
  masters = other25.masters;
  sys_status = other25.sys_status;
  __isset = other25.__isset;
  return *this;
}
void MasterCheckModel::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "MasterCheckModel(";
  out << "data=" << to_string(data);
  out << ", " << "masters=" << to_string(masters);
  out << ", " << "sys_status=" << to_string(sys_status);
  out << ")";
}


RatingsModel::~RatingsModel() throw() {
}


void RatingsModel::__set_dgRating(const std::vector<std::vector<std::string> > & val) {
  this->dgRating = val;
}

void RatingsModel::__set_epsRating(const std::vector<std::vector<std::string> > & val) {
  this->epsRating = val;
}

void RatingsModel::__set_rsRating(const std::vector<std::vector<std::string> > & val) {
  this->rsRating = val;
}

void RatingsModel::__set_accDis(const std::vector<std::vector<std::string> > & val) {
  this->accDis = val;
}

void RatingsModel::__set_groupRank(const std::vector<std::vector<std::string> > & val) {
  this->groupRank = val;
}

void RatingsModel::__set_marketOutlook(const std::vector<std::vector<std::string> > & val) {
  this->marketOutlook = val;
}

void RatingsModel::__set_sys_status(const int64_t val) {
  this->sys_status = val;
}
std::ostream& operator<<(std::ostream& out, const RatingsModel& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t RatingsModel::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->dgRating.clear();
            uint32_t _size26;
            ::apache::thrift::protocol::TType _etype29;
            xfer += iprot->readListBegin(_etype29, _size26);
            this->dgRating.resize(_size26);
            uint32_t _i30;
            for (_i30 = 0; _i30 < _size26; ++_i30)
            {
              {
                this->dgRating[_i30].clear();
                uint32_t _size31;
                ::apache::thrift::protocol::TType _etype34;
                xfer += iprot->readListBegin(_etype34, _size31);
                this->dgRating[_i30].resize(_size31);
                uint32_t _i35;
                for (_i35 = 0; _i35 < _size31; ++_i35)
                {
                  xfer += iprot->readString(this->dgRating[_i30][_i35]);
                }
                xfer += iprot->readListEnd();
              }
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.dgRating = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->epsRating.clear();
            uint32_t _size36;
            ::apache::thrift::protocol::TType _etype39;
            xfer += iprot->readListBegin(_etype39, _size36);
            this->epsRating.resize(_size36);
            uint32_t _i40;
            for (_i40 = 0; _i40 < _size36; ++_i40)
            {
              {
                this->epsRating[_i40].clear();
                uint32_t _size41;
                ::apache::thrift::protocol::TType _etype44;
                xfer += iprot->readListBegin(_etype44, _size41);
                this->epsRating[_i40].resize(_size41);
                uint32_t _i45;
                for (_i45 = 0; _i45 < _size41; ++_i45)
                {
                  xfer += iprot->readString(this->epsRating[_i40][_i45]);
                }
                xfer += iprot->readListEnd();
              }
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.epsRating = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->rsRating.clear();
            uint32_t _size46;
            ::apache::thrift::protocol::TType _etype49;
            xfer += iprot->readListBegin(_etype49, _size46);
            this->rsRating.resize(_size46);
            uint32_t _i50;
            for (_i50 = 0; _i50 < _size46; ++_i50)
            {
              {
                this->rsRating[_i50].clear();
                uint32_t _size51;
                ::apache::thrift::protocol::TType _etype54;
                xfer += iprot->readListBegin(_etype54, _size51);
                this->rsRating[_i50].resize(_size51);
                uint32_t _i55;
                for (_i55 = 0; _i55 < _size51; ++_i55)
                {
                  xfer += iprot->readString(this->rsRating[_i50][_i55]);
                }
                xfer += iprot->readListEnd();
              }
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.rsRating = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->accDis.clear();
            uint32_t _size56;
            ::apache::thrift::protocol::TType _etype59;
            xfer += iprot->readListBegin(_etype59, _size56);
            this->accDis.resize(_size56);
            uint32_t _i60;
            for (_i60 = 0; _i60 < _size56; ++_i60)
            {
              {
                this->accDis[_i60].clear();
                uint32_t _size61;
                ::apache::thrift::protocol::TType _etype64;
                xfer += iprot->readListBegin(_etype64, _size61);
                this->accDis[_i60].resize(_size61);
                uint32_t _i65;
                for (_i65 = 0; _i65 < _size61; ++_i65)
                {
                  xfer += iprot->readString(this->accDis[_i60][_i65]);
                }
                xfer += iprot->readListEnd();
              }
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.accDis = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->groupRank.clear();
            uint32_t _size66;
            ::apache::thrift::protocol::TType _etype69;
            xfer += iprot->readListBegin(_etype69, _size66);
            this->groupRank.resize(_size66);
            uint32_t _i70;
            for (_i70 = 0; _i70 < _size66; ++_i70)
            {
              {
                this->groupRank[_i70].clear();
                uint32_t _size71;
                ::apache::thrift::protocol::TType _etype74;
                xfer += iprot->readListBegin(_etype74, _size71);
                this->groupRank[_i70].resize(_size71);
                uint32_t _i75;
                for (_i75 = 0; _i75 < _size71; ++_i75)
                {
                  xfer += iprot->readString(this->groupRank[_i70][_i75]);
                }
                xfer += iprot->readListEnd();
              }
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.groupRank = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->marketOutlook.clear();
            uint32_t _size76;
            ::apache::thrift::protocol::TType _etype79;
            xfer += iprot->readListBegin(_etype79, _size76);
            this->marketOutlook.resize(_size76);
            uint32_t _i80;
            for (_i80 = 0; _i80 < _size76; ++_i80)
            {
              {
                this->marketOutlook[_i80].clear();
                uint32_t _size81;
                ::apache::thrift::protocol::TType _etype84;
                xfer += iprot->readListBegin(_etype84, _size81);
                this->marketOutlook[_i80].resize(_size81);
                uint32_t _i85;
                for (_i85 = 0; _i85 < _size81; ++_i85)
                {
                  xfer += iprot->readString(this->marketOutlook[_i80][_i85]);
                }
                xfer += iprot->readListEnd();
              }
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.marketOutlook = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->sys_status);
          this->__isset.sys_status = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t RatingsModel::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("RatingsModel");

  xfer += oprot->writeFieldBegin("dgRating", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_LIST, static_cast<uint32_t>(this->dgRating.size()));
    std::vector<std::vector<std::string> > ::const_iterator _iter86;
    for (_iter86 = this->dgRating.begin(); _iter86 != this->dgRating.end(); ++_iter86)
    {
      {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*_iter86).size()));
        std::vector<std::string> ::const_iterator _iter87;
        for (_iter87 = (*_iter86).begin(); _iter87 != (*_iter86).end(); ++_iter87)
        {
          xfer += oprot->writeString((*_iter87));
        }
        xfer += oprot->writeListEnd();
      }
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("epsRating", ::apache::thrift::protocol::T_LIST, 2);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_LIST, static_cast<uint32_t>(this->epsRating.size()));
    std::vector<std::vector<std::string> > ::const_iterator _iter88;
    for (_iter88 = this->epsRating.begin(); _iter88 != this->epsRating.end(); ++_iter88)
    {
      {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*_iter88).size()));
        std::vector<std::string> ::const_iterator _iter89;
        for (_iter89 = (*_iter88).begin(); _iter89 != (*_iter88).end(); ++_iter89)
        {
          xfer += oprot->writeString((*_iter89));
        }
        xfer += oprot->writeListEnd();
      }
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("rsRating", ::apache::thrift::protocol::T_LIST, 3);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_LIST, static_cast<uint32_t>(this->rsRating.size()));
    std::vector<std::vector<std::string> > ::const_iterator _iter90;
    for (_iter90 = this->rsRating.begin(); _iter90 != this->rsRating.end(); ++_iter90)
    {
      {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*_iter90).size()));
        std::vector<std::string> ::const_iterator _iter91;
        for (_iter91 = (*_iter90).begin(); _iter91 != (*_iter90).end(); ++_iter91)
        {
          xfer += oprot->writeString((*_iter91));
        }
        xfer += oprot->writeListEnd();
      }
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("accDis", ::apache::thrift::protocol::T_LIST, 4);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_LIST, static_cast<uint32_t>(this->accDis.size()));
    std::vector<std::vector<std::string> > ::const_iterator _iter92;
    for (_iter92 = this->accDis.begin(); _iter92 != this->accDis.end(); ++_iter92)
    {
      {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*_iter92).size()));
        std::vector<std::string> ::const_iterator _iter93;
        for (_iter93 = (*_iter92).begin(); _iter93 != (*_iter92).end(); ++_iter93)
        {
          xfer += oprot->writeString((*_iter93));
        }
        xfer += oprot->writeListEnd();
      }
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("groupRank", ::apache::thrift::protocol::T_LIST, 5);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_LIST, static_cast<uint32_t>(this->groupRank.size()));
    std::vector<std::vector<std::string> > ::const_iterator _iter94;
    for (_iter94 = this->groupRank.begin(); _iter94 != this->groupRank.end(); ++_iter94)
    {
      {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*_iter94).size()));
        std::vector<std::string> ::const_iterator _iter95;
        for (_iter95 = (*_iter94).begin(); _iter95 != (*_iter94).end(); ++_iter95)
        {
          xfer += oprot->writeString((*_iter95));
        }
        xfer += oprot->writeListEnd();
      }
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("marketOutlook", ::apache::thrift::protocol::T_LIST, 6);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_LIST, static_cast<uint32_t>(this->marketOutlook.size()));
    std::vector<std::vector<std::string> > ::const_iterator _iter96;
    for (_iter96 = this->marketOutlook.begin(); _iter96 != this->marketOutlook.end(); ++_iter96)
    {
      {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*_iter96).size()));
        std::vector<std::string> ::const_iterator _iter97;
        for (_iter97 = (*_iter96).begin(); _iter97 != (*_iter96).end(); ++_iter97)
        {
          xfer += oprot->writeString((*_iter97));
        }
        xfer += oprot->writeListEnd();
      }
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("sys_status", ::apache::thrift::protocol::T_I64, 7);
  xfer += oprot->writeI64(this->sys_status);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(RatingsModel &a, RatingsModel &b) {
  using ::std::swap;
  swap(a.dgRating, b.dgRating);
  swap(a.epsRating, b.epsRating);
  swap(a.rsRating, b.rsRating);
  swap(a.accDis, b.accDis);
  swap(a.groupRank, b.groupRank);
  swap(a.marketOutlook, b.marketOutlook);
  swap(a.sys_status, b.sys_status);
  swap(a.__isset, b.__isset);
}

RatingsModel::RatingsModel(const RatingsModel& other98) {
  dgRating = other98.dgRating;
  epsRating = other98.epsRating;
  rsRating = other98.rsRating;
  accDis = other98.accDis;
  groupRank = other98.groupRank;
  marketOutlook = other98.marketOutlook;
  sys_status = other98.sys_status;
  __isset = other98.__isset;
}
RatingsModel& RatingsModel::operator=(const RatingsModel& other99) {
  dgRating = other99.dgRating;
  epsRating = other99.epsRating;
  rsRating = other99.rsRating;
  accDis = other99.accDis;
  groupRank = other99.groupRank;
  marketOutlook = other99.marketOutlook;
  sys_status = other99.sys_status;
  __isset = other99.__isset;
  return *this;
}
void RatingsModel::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "RatingsModel(";
  out << "dgRating=" << to_string(dgRating);
  out << ", " << "epsRating=" << to_string(epsRating);
  out << ", " << "rsRating=" << to_string(rsRating);
  out << ", " << "accDis=" << to_string(accDis);
  out << ", " << "groupRank=" << to_string(groupRank);
  out << ", " << "marketOutlook=" << to_string(marketOutlook);
  out << ", " << "sys_status=" << to_string(sys_status);
  out << ")";
}


Top33Model::~Top33Model() throw() {
}


void Top33Model::__set_description(const std::string& val) {
  this->description = val;
}

void Top33Model::__set_data(const std::vector<std::vector<std::string> > & val) {
  this->data = val;
}

void Top33Model::__set_recentAdditions(const std::vector<std::vector<std::string> > & val) {
  this->recentAdditions = val;
}

void Top33Model::__set_recentRemovals(const std::vector<std::vector<std::string> > & val) {
  this->recentRemovals = val;
}

void Top33Model::__set_sys_status(const int64_t val) {
  this->sys_status = val;
}
std::ostream& operator<<(std::ostream& out, const Top33Model& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t Top33Model::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->description);
          this->__isset.description = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->data.clear();
            uint32_t _size100;
            ::apache::thrift::protocol::TType _etype103;
            xfer += iprot->readListBegin(_etype103, _size100);
            this->data.resize(_size100);
            uint32_t _i104;
            for (_i104 = 0; _i104 < _size100; ++_i104)
            {
              {
                this->data[_i104].clear();
                uint32_t _size105;
                ::apache::thrift::protocol::TType _etype108;
                xfer += iprot->readListBegin(_etype108, _size105);
                this->data[_i104].resize(_size105);
                uint32_t _i109;
                for (_i109 = 0; _i109 < _size105; ++_i109)
                {
                  xfer += iprot->readString(this->data[_i104][_i109]);
                }
                xfer += iprot->readListEnd();
              }
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.data = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->recentAdditions.clear();
            uint32_t _size110;
            ::apache::thrift::protocol::TType _etype113;
            xfer += iprot->readListBegin(_etype113, _size110);
            this->recentAdditions.resize(_size110);
            uint32_t _i114;
            for (_i114 = 0; _i114 < _size110; ++_i114)
            {
              {
                this->recentAdditions[_i114].clear();
                uint32_t _size115;
                ::apache::thrift::protocol::TType _etype118;
                xfer += iprot->readListBegin(_etype118, _size115);
                this->recentAdditions[_i114].resize(_size115);
                uint32_t _i119;
                for (_i119 = 0; _i119 < _size115; ++_i119)
                {
                  xfer += iprot->readString(this->recentAdditions[_i114][_i119]);
                }
                xfer += iprot->readListEnd();
              }
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.recentAdditions = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->recentRemovals.clear();
            uint32_t _size120;
            ::apache::thrift::protocol::TType _etype123;
            xfer += iprot->readListBegin(_etype123, _size120);
            this->recentRemovals.resize(_size120);
            uint32_t _i124;
            for (_i124 = 0; _i124 < _size120; ++_i124)
            {
              {
                this->recentRemovals[_i124].clear();
                uint32_t _size125;
                ::apache::thrift::protocol::TType _etype128;
                xfer += iprot->readListBegin(_etype128, _size125);
                this->recentRemovals[_i124].resize(_size125);
                uint32_t _i129;
                for (_i129 = 0; _i129 < _size125; ++_i129)
                {
                  xfer += iprot->readString(this->recentRemovals[_i124][_i129]);
                }
                xfer += iprot->readListEnd();
              }
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.recentRemovals = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->sys_status);
          this->__isset.sys_status = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t Top33Model::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("Top33Model");

  xfer += oprot->writeFieldBegin("description", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->description);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("data", ::apache::thrift::protocol::T_LIST, 2);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_LIST, static_cast<uint32_t>(this->data.size()));
    std::vector<std::vector<std::string> > ::const_iterator _iter130;
    for (_iter130 = this->data.begin(); _iter130 != this->data.end(); ++_iter130)
    {
      {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*_iter130).size()));
        std::vector<std::string> ::const_iterator _iter131;
        for (_iter131 = (*_iter130).begin(); _iter131 != (*_iter130).end(); ++_iter131)
        {
          xfer += oprot->writeString((*_iter131));
        }
        xfer += oprot->writeListEnd();
      }
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("recentAdditions", ::apache::thrift::protocol::T_LIST, 3);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_LIST, static_cast<uint32_t>(this->recentAdditions.size()));
    std::vector<std::vector<std::string> > ::const_iterator _iter132;
    for (_iter132 = this->recentAdditions.begin(); _iter132 != this->recentAdditions.end(); ++_iter132)
    {
      {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*_iter132).size()));
        std::vector<std::string> ::const_iterator _iter133;
        for (_iter133 = (*_iter132).begin(); _iter133 != (*_iter132).end(); ++_iter133)
        {
          xfer += oprot->writeString((*_iter133));
        }
        xfer += oprot->writeListEnd();
      }
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("recentRemovals", ::apache::thrift::protocol::T_LIST, 4);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_LIST, static_cast<uint32_t>(this->recentRemovals.size()));
    std::vector<std::vector<std::string> > ::const_iterator _iter134;
    for (_iter134 = this->recentRemovals.begin(); _iter134 != this->recentRemovals.end(); ++_iter134)
    {
      {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*_iter134).size()));
        std::vector<std::string> ::const_iterator _iter135;
        for (_iter135 = (*_iter134).begin(); _iter135 != (*_iter134).end(); ++_iter135)
        {
          xfer += oprot->writeString((*_iter135));
        }
        xfer += oprot->writeListEnd();
      }
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("sys_status", ::apache::thrift::protocol::T_I64, 5);
  xfer += oprot->writeI64(this->sys_status);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(Top33Model &a, Top33Model &b) {
  using ::std::swap;
  swap(a.description, b.description);
  swap(a.data, b.data);
  swap(a.recentAdditions, b.recentAdditions);
  swap(a.recentRemovals, b.recentRemovals);
  swap(a.sys_status, b.sys_status);
  swap(a.__isset, b.__isset);
}

Top33Model::Top33Model(const Top33Model& other136) {
  description = other136.description;
  data = other136.data;
  recentAdditions = other136.recentAdditions;
  recentRemovals = other136.recentRemovals;
  sys_status = other136.sys_status;
  __isset = other136.__isset;
}
Top33Model& Top33Model::operator=(const Top33Model& other137) {
  description = other137.description;
  data = other137.data;
  recentAdditions = other137.recentAdditions;
  recentRemovals = other137.recentRemovals;
  sys_status = other137.sys_status;
  __isset = other137.__isset;
  return *this;
}
void Top33Model::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "Top33Model(";
  out << "description=" << to_string(description);
  out << ", " << "data=" << to_string(data);
  out << ", " << "recentAdditions=" << to_string(recentAdditions);
  out << ", " << "recentRemovals=" << to_string(recentRemovals);
  out << ", " << "sys_status=" << to_string(sys_status);
  out << ")";
}


StockListModel::~StockListModel() throw() {
}


void StockListModel::__set_description(const std::string& val) {
  this->description = val;
}

void StockListModel::__set_data(const std::vector<std::vector<std::string> > & val) {
  this->data = val;
}

void StockListModel::__set_sys_status(const int64_t val) {
  this->sys_status = val;
}
std::ostream& operator<<(std::ostream& out, const StockListModel& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t StockListModel::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->description);
          this->__isset.description = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->data.clear();
            uint32_t _size138;
            ::apache::thrift::protocol::TType _etype141;
            xfer += iprot->readListBegin(_etype141, _size138);
            this->data.resize(_size138);
            uint32_t _i142;
            for (_i142 = 0; _i142 < _size138; ++_i142)
            {
              {
                this->data[_i142].clear();
                uint32_t _size143;
                ::apache::thrift::protocol::TType _etype146;
                xfer += iprot->readListBegin(_etype146, _size143);
                this->data[_i142].resize(_size143);
                uint32_t _i147;
                for (_i147 = 0; _i147 < _size143; ++_i147)
                {
                  xfer += iprot->readString(this->data[_i142][_i147]);
                }
                xfer += iprot->readListEnd();
              }
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.data = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->sys_status);
          this->__isset.sys_status = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t StockListModel::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("StockListModel");

  xfer += oprot->writeFieldBegin("description", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->description);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("data", ::apache::thrift::protocol::T_LIST, 2);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_LIST, static_cast<uint32_t>(this->data.size()));
    std::vector<std::vector<std::string> > ::const_iterator _iter148;
    for (_iter148 = this->data.begin(); _iter148 != this->data.end(); ++_iter148)
    {
      {
        xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*_iter148).size()));
        std::vector<std::string> ::const_iterator _iter149;
        for (_iter149 = (*_iter148).begin(); _iter149 != (*_iter148).end(); ++_iter149)
        {
          xfer += oprot->writeString((*_iter149));
        }
        xfer += oprot->writeListEnd();
      }
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("sys_status", ::apache::thrift::protocol::T_I64, 3);
  xfer += oprot->writeI64(this->sys_status);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(StockListModel &a, StockListModel &b) {
  using ::std::swap;
  swap(a.description, b.description);
  swap(a.data, b.data);
  swap(a.sys_status, b.sys_status);
  swap(a.__isset, b.__isset);
}

StockListModel::StockListModel(const StockListModel& other150) {
  description = other150.description;
  data = other150.data;
  sys_status = other150.sys_status;
  __isset = other150.__isset;
}
StockListModel& StockListModel::operator=(const StockListModel& other151) {
  description = other151.description;
  data = other151.data;
  sys_status = other151.sys_status;
  __isset = other151.__isset;
  return *this;
}
void StockListModel::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "StockListModel(";
  out << "description=" << to_string(description);
  out << ", " << "data=" << to_string(data);
  out << ", " << "sys_status=" << to_string(sys_status);
  out << ")";
}

} // namespace
