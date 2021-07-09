Giả sử ta có dãy các chương trình:
d = {5, 3, 1, 2, 8, 7, 4, 6}
n = 8

Hai băng nhớ b1, b2 có độ dài L = 10

Trước tiên ta sắp xếp dãy d tăng dần
=> d = {1, 2, 3, 4, 5, 6, 7, 8}

Ta lần lượt lấy từng chương trình từ trái qua phải thêm vào b1,
sau khi thêm 1 trương trình vào b1, ta lại quay sang thêm vào b2

Bước 1: b1 = {1}
        b2 = {}

Bước 2: b1 = {1}
        b2 = {2}

Bước 3: b1 = {1, 3}
        b2 = {2}

Bước 4: b1 = {1, 3}
        b2 = {2, 4}

Bước 5: b1 = {1, 3, 5}
        b2 = {2, 4}

Bước 6: b1 = {1, 3, 5}
        b2 = {2, 4} // Không thể thêm 6 vào b2 được nữa vì độ dài băng nhớ không đủ

Bước 6: b1 = {1, 3, 5} // Không thể thêm 6 vào b1 được nữa vì độ dài băng nhớ không đủ
        b2 = {2, 4} 