#!/usr/bin/env python
import hashlib
import sys
from urlparse import urljoin
import requests
from database import get_secid, conn, r
from util import auth
from won import ApiService
from won.ttypes import Top33Model, RatingsModel, StockListModel, MasterCheckModel
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol
from thrift.server import TServer


sys.path.append('gen-py')
global null
null = None
tap_root = "tap_root/"



class ApiServiceHandler:
    def master_checklist(self,device_uuid,access_token,mic, symbol):
        """
        master_checklist
        :param mic:
        :param symbol:
        :return: mastercheck
        """

        if not auth(device_uuid,access_token):
            sys_status = 41001
            data = []
            masters = []
        else:
            try:
                sec_id = get_secid(conn, mic, symbol)
                url = urljoin(tap_root, '/api/MSFUNDAMENTAL/stock.evaluation')
                rawdata = requests.get(url, {"securityId": sec_id, "lang": "zh_CN"}).content
                dictdata = eval(rawdata)
                data = [[str(item) for item in itemlist] for itemlist in dictdata['data']]
                masters = [[str(item) for item in itemlist] for itemlist in dictdata['masters']]
                sys_status = 0
            except:
                data = []
                masters = []
                sys_status = -1
        mastercheck = MasterCheckModel(data=data,masters=masters,sys_status=sys_status)
        return mastercheck

    def ratings(self,device_uuid,access_token, mic, symbol):
        """
        ratings
        :param mic:
        :param symbol:
        :return: ratings
        """
        if not auth(device_uuid, access_token):
            sys_status = 41001
            dgRating = []
            epsRating = []
            rsRating = []
            accDis = []
            groupRank = []
            marketOutlook = []
        else:
            try:
                sec_id = get_secid(conn, mic, symbol)
                url = urljoin(tap_root, '/api/MSFUNDAMENTAL/stock.wisdom')
                rawdata = requests.get(url, {"securityId": sec_id, "lang": "zh_CN"}).content
                dictdata = eval(rawdata)
                dgRating = [[str(item) for item in itemlist] for itemlist in dictdata['dgRating']]
                epsRating = [[str(item) for item in itemlist] for itemlist in dictdata['epsRating']]
                rsRating = [[str(item) for item in itemlist] for itemlist in dictdata['rsRating']]
                accDis = [[str(item) for item in itemlist] for itemlist in dictdata['accDis']]
                groupRank = [[str(item) for item in itemlist] for itemlist in dictdata['groupRank']]
                marketOutlook = [[str(item) for item in itemlist] for itemlist in dictdata['marketOutlook']]
                sys_status = 0
            except:
                dgRating = []
                epsRating = []
                rsRating = []
                accDis = []
                groupRank = []
                marketOutlook = []
                sys_status = -1
        ratings = RatingsModel(dgRating=dgRating,epsRating=epsRating,rsRating=rsRating,accDis=accDis,groupRank=groupRank,marketOutlook=marketOutlook,sys_status=sys_status)
        return ratings

    def top33(self,device_uuid,access_token):
        """
        top33
        :return: top33
        """
        if not auth(device_uuid, access_token):
            sys_status = 41001
            description = ''
            data = []
            recentAdditions = []
            recentRemovals = []
        else:
            try:
                url = urljoin(tap_root, '/api/PORTFOLIO.ASHARES/top33')
                rawdata = requests.get(url, {"query": "", "lang": "zh_CN", "sort": "D:DGRATING,D:RSRATING"}).content
                dictdata = eval(rawdata)
                description = dictdata['description']
                data = [[str(item) for item in itemlist] for itemlist in dictdata['data']]
                recentAdditions = [[str(item) for item in itemlist] for itemlist in dictdata['recentAdditions']]
                recentRemovals = [[str(item) for item in itemlist] for itemlist in dictdata['recentRemovals']]
                sys_status = 0
            except:
                description = ''
                data = []
                recentAdditions = []
                recentRemovals = []
                sys_status = -1
        top33 = Top33Model(description=description,data=data,recentAdditions=recentAdditions,recentRemovals=recentRemovals,sys_status=sys_status)
        return top33

    def near_pivot(self,device_uuid,access_token):
        """
        near_pivot
        :return: near_pivot
        """
        if not auth(device_uuid, access_token):
            sys_status = 41001
            description = ''
            data = []
        else:
            try:
                url = urljoin(tap_root, '/api/PORTFOLIO.ASHARES/buyPoint')
                rawdata = requests.get(url, {"query": "", "lang": "zh_CN", "sort": "D:CHANGEVSPIVOT"}).content
                dictdata = eval(rawdata)
                description = dictdata['description']
                data = [[str(item) for item in itemlist] for itemlist in dictdata['data']]
                sys_status = 0
            except:
                description = ''
                data = []
                sys_status = -1
        stockList = StockListModel(description=description,data=data,sys_status=sys_status)
        return stockList

    def volume_up(self,device_uuid,access_token):
        """
        volume_up
        :return: volume_up
        """
        if not auth(device_uuid, access_token):
            sys_status = 41001
            description = ''
            data = []
        else:
            try:
                url = urljoin(tap_root, '/api/PORTFOLIO.ASHARES/upOnVolume')
                rawdata = requests.get(url, {"query": "", "lang": "zh_CN", "sort": "D:AVGVOL50"}).content
                dictdata = eval(rawdata)
                description = dictdata['description']
                data = [[str(item) for item in itemlist] for itemlist in dictdata['data']]
                sys_status = 0
            except:
                description = ''
                data = []
                sys_status = -1
        stockList = StockListModel(description=description, data=data,sys_status=sys_status)
        return stockList

    def dividend_stocks(self,device_uuid,access_token):
        """
        dividend_stocks
        :return: dividend_stocks
        """
        if not auth(device_uuid, access_token):
            sys_status = 41001
            description = ''
            data = []
        else:
            try:
                url = urljoin(tap_root, '/api/PORTFOLIO.ASHARES/incomeStocks')
                rawdata = requests.get(url, {"query": "", "lang": "zh_CN", "sort": "D:YIELD"}).content
                dictdata = eval(rawdata)
                description = dictdata['description']
                data = [[str(item) for item in itemlist] for itemlist in dictdata['data']]
                sys_status = 0
            except:
                description = ''
                data = []
                sys_status = -1
        stockList = StockListModel(description=description, data=data,sys_status=sys_status)
        return stockList

    def registered(self,won_key, device_uuid, timestamp, access_token):
        """
        registered
        :param won_key:
        :param timestamp:
        :param access_token:
        :param device_uuid:
        :return: sys_status
        """
        sys_status = 0
        cursor = conn.cursor()
        cursor.execute("SELECT won_secret,expires_in FROM authentication where won_key = ? and available = 1 ",
                       (won_key,))
        row = cursor.fetchone()
        if not row:
            sys_status = 41002
        else:
            won_secret = row[0]
            expires_in = row[1]
            data = [timestamp, won_key, won_secret]
            data = sorted(data)
            data = ''.join(data)
            _access_token = hashlib.sha256(data).hexdigest()

            if _access_token == access_token:
                cursor.execute(" insert into usage_record (won_key,device_uuid,expires_in) values(?,?,?)",
                               (won_key, device_uuid, expires_in))
                r.set(device_uuid, access_token, ex=expires_in)
            else:
                sys_status = 41001
        return sys_status

if __name__ == '__main__':
    handler = ApiServiceHandler()
    processor = ApiService.Processor(handler)
    transport = TSocket.TServerSocket(host='192.168.202.53', port=9090)
    tfactory = TTransport.TBufferedTransportFactory()
    pfactory = TBinaryProtocol.TBinaryProtocolFactory()
    server = TServer.TSimpleServer(processor, transport, tfactory, pfactory)
    print('Starting the server...')
    server.serve()
    print('done.')
