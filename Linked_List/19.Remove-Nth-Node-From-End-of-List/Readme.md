# 19.Remove-Nth-Node-From-End-of-List

假設鏈表長度為size，要刪除倒數第n個節點，要操作第size-n個節點，因此要思考怎麼高效獲取這顆節點。一開始無法知道size，正難則反，先讓快指針向前走n步，接下快指針走到底的步數恰好就是size-n步。接著再用一根慢指針走到第size-n個節點執行刪除操作。
