* Chia để trị
Ý tưởng của thuật toán là 
1. Chia mảng thành 2 nửa
2. Trả về giá trị max của 3 phần
    2a. Max của nửa bên trái
    2b. Max của nửa bên phải
    2c. Max của nửa ở giữa (dãy đi qua điểm midpoint)

Các tìm max của 2a, 2b thì ta chỉ cần gọi đệ quy
Còn tìm max của 2c thì làm như sau:
    + Tìm max của bên trái mid (left -> mid)
    + Tìm max của bên phải mid (mid + 1 -> right)
    + Cộng 2 nửa vừa tìm được với nhau rồi tìm ra cái lớn nhất max(trái, phải, hay trái + phải)

VD: 
-2 11 -4 13 -5 2

=> Ta chia mảng thành 2 nửa
-2 11 -4 | 13 -5 2

mid = a[5/2] = a[2] = -4 

=> Max của bên trái là 11 (2a)
=> Max của bên phải là 13 (2b)
=> Tìm max ở giữa:
    + Max của (left -> mid) là: 11 + (-4) = 7
    + Max của (mid + 1 -> right) là: 13 
    + Cổng 2 nửa: 7 + 13 = 20
    => max(20, 13, 7) = 20 (2c)

Vậy max của cả dãy = max(11, 13, 20) = 20