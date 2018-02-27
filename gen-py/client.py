import hashlib
import sys

import time

from won import ApiService

sys.path.append('gen-py')
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol


if __name__ == '__main__':

    # Make socket
    transport = TSocket.TSocket('192.168.202.53', 9090)

    # Buffering is critical. Raw sockets are very slow
    transport = TTransport.TBufferedTransport(transport)

    # Wrap in a protocol
    protocol = TBinaryProtocol.TBinaryProtocol(transport)

    # Create a client to use the protocol encoder
    client = ApiService.Client(protocol)

    # Connect!
    transport.open()

    #registered
    won_key = "dfezs3Nm4v"
    won_secret = "1rnILSqP4CEKYA8WMy3x"
    timestamp = str(int(time.time()))
    device_uuid = "comzfxf-12312312394005"
    data = [str(int(time.time())), won_key, won_secret]
    data = sorted(data)
    data = ''.join(data)
    access_token = hashlib.sha256(data).hexdigest()
    result = client.registered(won_key, device_uuid, timestamp, access_token)
    print result

    # method call
    data1 = client.master_checklist(device_uuid,access_token,'XSHG','600002')
    data2 = client.ratings(device_uuid,access_token,'XSHG', '600000')
    data3 = client.top33(device_uuid,access_token)
    data4 = client.near_pivot(device_uuid,access_token)
    data5 = client.volume_up(device_uuid,access_token)
    data6 = client.dividend_stocks(device_uuid,access_token)
    print data1
    print data2
    print data3
    print data4
    print data5
    print data6

    # Close!
    transport.close()
