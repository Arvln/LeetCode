# 1080.Insufficient-Nodes-in-Root-to-Leaf-Paths

根到葉路徑和嚴格小於limit需要將葉節點刪除，刪除操作後父節點不指向其他合格路徑的也一併刪除。跟常規刪除唯一不同在於刪除操作仰賴對原始樹結構造成的影響。因此先將原始樹葉節點中不合限制都刪除，再評估對非葉節點的影響，假設刪除操作讓原始樹中非葉節點變為葉節點則一併刪除，若是仍為非葉節點則調整左右子樹結構。
