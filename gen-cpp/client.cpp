//
// Created by kjiang on 2018/2/23.
//
#include <iostream>
#include <sys/time.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <sstream>
#include <openssl/sha.h>
#include "ApiService.h"

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;
using namespace won;

using namespace std;

template<typename T> string toString(const T& t){
    ostringstream oss;
    oss<<t;
    return oss.str();
}


void sha256(const string &srcStr, string &encodedHexStr)
{
    // 调用sha256哈希
    unsigned char mdStr[33] = {0};
    SHA256((const unsigned char *)srcStr.c_str(), srcStr.length(), mdStr);

    // 哈希后的字符串
    string encodedStr = string((const char *)mdStr);
    char buf[65] = {0};
    char tmp[3] = {0};
    for (int i = 0; i < 32; i++)
    {
        sprintf(tmp, "%02x", mdStr[i]);
        strcat(buf, tmp);
    }
    encodedHexStr = string(buf);
}

int main() {
    stdcxx::shared_ptr<TTransport> socket(new TSocket("192.168.202.53", 9090));
    stdcxx::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
    stdcxx::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
    ApiServiceClient client(protocol);

    try {
        transport->open();
        //access_token
        string access_token;

        // 设备唯一标识码
        string device_uuid="anxin-12312312394005";

        //时间戳
        string timestamp = toString(time(NULL));

        //公钥
        string won_key = "dfezs3Nm4v";

        //私钥
        string won_secret = "1rnILSqP4CEKYA8WMy3x";

        // 将时间戳,公钥,私钥进行排序后拼接在一起
        string datalist[] = {timestamp,won_key,won_secret};
        sort(datalist,datalist+3);
        string data = "";
        for(int i = 0 ; i < 3; i ++)
            data += datalist[i];

        // 对拼接在一起字符串进sha256加密,access_token为其十六进制摘要
        sha256(data,access_token);
        cout << access_token<< endl;

        // 授权
        int64_t result = client.registered(won_key, device_uuid, timestamp, access_token);
        cout <<result<< endl;

        //大师评股
        MasterCheckModel mastercheckdata;
        client.master_checklist(mastercheckdata,device_uuid,access_token,"XSHG","600000");
        cout << mastercheckdata << endl;

        //股票评级
        RatingsModel ratingsdata;
        client.ratings(ratingsdata,device_uuid,access_token,"XSHG","600000");
        cout << ratingsdata << endl;

        //顶级33列表
        Top33Model top33data;
        client.top33(top33data,device_uuid,access_token);
        cout << top33data << endl;

        //接近买点列表
        StockListModel near_pivotdata;
        client.near_pivot(near_pivotdata,device_uuid,access_token);
        cout << near_pivotdata << endl;

        //成交量突破列表
        StockListModel volume_updata;
        client.volume_up(volume_updata,device_uuid,access_token);
        cout << volume_updata << endl;

        //收益型股票列表
        StockListModel dividend_stocksdata;
        client.dividend_stocks(dividend_stocksdata,device_uuid,access_token);
        cout << dividend_stocksdata << endl;

        transport->close();
    } catch (TException& tx) {
        cout << "ERROR: " << tx.what() << endl;
    }
}

