# coding=utf8
from mscommon.database import connect
from mscommon.database import redis_cache

r = redis_cache()
_SECID_CACHE = {}
conn = connect("msintldb")

def get_secid(conn, mic, symbol):
    key = (mic, symbol)

    sec_id = _SECID_CACHE.get(key)
    if not sec_id:
        cursor = conn.cursor()
        cursor.execute("select top 1 securityId from msd_Fundamental where mic=? and symbol=?", (mic, symbol))
        row = cursor.fetchone()
        if row:
            _SECID_CACHE[key] = row[0]

    return _SECID_CACHE.get(key)
