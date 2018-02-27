namespace cpp won
namespace py won
namespace java won

struct MasterCheckModel{
  1: list<list<string>>  data,
  2: list<list<string>>  masters,
  3: i64 sys_status
}

struct RatingsModel{
  1: list<list<string>>  dgRating,
  2: list<list<string>> epsRating,
  3: list<list<string>> rsRating,
  4: list<list<string>>  accDis,
  5: list<list<string>>  groupRank,
  6: list<list<string>>  marketOutlook,
  7: i64 sys_status
}
struct Top33Model{
  1: string description,
  2: list<list<string>>  data,
  3: list<list<string>>  recentAdditions,
  4: list<list<string>>  recentRemovals,
  5: i64 sys_status
}

struct StockListModel{
  1: string description,
  2: list<list<string>>  data
  3: i64 sys_status
}


service ApiService {
 MasterCheckModel master_checklist(1:string device_uuid,2:string access_token,3:string mic, 4:string symbol),
 RatingsModel ratings(1:string device_uuid,2:string access_token,3:string mic, 4:string symbol),
 Top33Model top33(1:string device_uuid,2:string access_token),
 StockListModel near_pivot(1:string device_uuid,2:string access_token),
 StockListModel volume_up(1:string device_uuid,2:string access_token),
 StockListModel dividend_stocks(1:string device_uuid,2:string access_token)
 i64 registered(1:string won_key,2:string device_uuid,3:string timestamp,4:string access_token)
}

