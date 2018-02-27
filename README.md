thrift RPC
================


Table of Contents
-----------------

  * [Python](./gen-py)
  * [Java](./gen-java)
  * [Cpp](./gen-cpp)


授权 
------

```
registered(won_key, device_uuid, timestamp, access_token)
```

####  参数说明
**won_key**

提供的公钥

**won_secret**

提供的私钥

**device_uuid**

设备唯一标识码

**timestamp**

时间戳 只保留整数部分，并转化为字符串

**access_token**

身份令牌

根据**won_key**、**won_secret**和**timestamp**生成的**access_token**

access_token生成流程

首先对 won_key、won_secret、timestamp进行排序后拼接在一起 然后做 sha256 加密，customer_token为 sha256 后的十六进制摘要，示例（python3）：


```
timestamp = str(int(time.time()))

won_key = "dfezs3Nm4v"

won_secret = "1rnILSqP4CEKYA8WMy3x"

data = [now, customer_key, customer_secret]

data = sorted(data)

data = "".join(data)
	
customer_token=hashlib.sha256(data.encode("utf8")).hexdigest()
```
**返回结果**


```
sys_status
```
[sys_status返回码说明](#sys_status)

大师评股
------

```
master_checklist(device_uuid,access_token,mic,symbol)
```
####  参数说明
**device_uuid**

授权时指定的设备唯一标识码

**access_token**

授权时生成的access_token

**mic**

市场代码：上交所代码 XSHG，深交所代码 XSHE


**symbol**

股票代码

**返回结果**


```
MasterCheckModel
```


股票评级
------

```
ratings(device_uuid,access_token,mic,symbol)
```
####  参数说明
**device_uuid**

授权时指定的设备唯一标识码

**access_token**

授权时生成的access_token

**mic**

市场代码：上交所代码 XSHG，深交所代码 XSHE


**symbol**

股票代码

**返回结果**


```
RatingsModel
```

顶级33列表
------

```
top33(top33data,device_uuid,access_token)
```
####  参数说明
**device_uuid**

授权时指定的设备唯一标识码

**access_token**

授权时生成的access_token


**返回结果**


```
Top33Model
```

接近买点列表
------

```
near_pivot(near_pivotdata,device_uuid,access_token)
```
####  参数说明
**device_uuid**

授权时指定的设备唯一标识码

**access_token**

授权时生成的access_token


**返回结果**


```
StockListModel
```


成交量突破列表
------

```
volume_up(volume_updata,device_uuid,access_token)
```
####  参数说明
**device_uuid**

授权时指定的设备唯一标识码

**access_token**

授权时生成的access_token


**返回结果**


```
StockListModel
```

收益型股票列表
------

```
dividend_stocks(dividend_stocksdata,device_uuid,access_token)
```
####  参数说明
**device_uuid**

授权时指定的设备唯一标识码

**access_token**

授权时生成的access_token


**返回结果**


```
StockListModel
```

sys_status
-------

sys_status | 错误信息
---|---
-1| 系统繁忙，请稍候再试
0| 请求成功
41001|access_token 错误
41002|won_key 不存在 或者 当前won_key被禁用









