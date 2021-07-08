https://open.kattis.com/problems/plantingtrees

Đề bài:
Cho n hạt giống có số ngày ra hoa tương ứng là d1 , d2 , …, dn . Một bác nông dân
trồng mỗi ngày một hạt giống. (Bác nông dân mất 1 ngày để trồng 1 cây) Viết chương trình tìm số ngày sớm nhất để bác
nông dân tổ chức bữa tiệc ngoài vườn khi tất cả các hạt giống này đã trưởng
thành và nở hoa.

Giả sử ta có dữ liệu đầu vào:
4
2 3 4 3

Ta cần sắp xếp giảm dần:

4| 3 3 2    Ngày 1: trồng cây thứ nhất
4 3| 3 2    Ngày 2: trồng cây thứ 2, cây thứ nhất vẫn còn 4 ngày vì mỗi cây mất 1 ngày mới được trồng xong, nên sang ngày thứ 2 cây thứ nhất mới trồng xong
3 3 3| 2    Ngày 3: trồng cây thứ 3, cây thứ nhất còn 3 ngày, cây thứ 2 vẫn còn 3 ngày vì nó cũng mất 1 ngày mới được trồng xong
2 2 3 2|    Ngày 4: tương tự
1 1 2 2     Ngày 5: tương tự nhưng đến ngày thứ 5 thì cây thứ 4 mới trồng xong

=> Vậy cần tối đa 2 ngày nữa thì mới xong (2 là max của mảng hiện tại)
=> tổng số ngày = 5 + 2 
=> tongNgay = n + 1 + max


* Trường hợp đặc biệt:

Giả sử ta có dữ liệu đầu vào:
4
3 3 4 3


4| 3 3 3
4 3| 3 3
3 3 3| 3
2 2 3 3|    Ngày 4:
1 1 2 3     Ngày 5:

Nếu ở trường hợp thường bên trên, ta có thể chỉ cần tính đến ngày thứ 4
rồi tìm được max = 3 => tongNgay = n + max (chẳng phải đơn giản hơn sao)
 - Nhưng tại sao lại phải tính đến ngày thứ 5?
 - Ta có thể thấy ở trường hợp đặc biệt nếu dừng ở ngày thứ 4
    thì max = 3 => tongNgay = n + max = 4 + 3 = 7 (đáp án sai)
    Còn nếu dừng ở ngày thứ 5: max = 3 => tongNgay = n + 1 + max = 4 + 1 + 3 = 8 (đáp án đúng)
 - Ta không thể dừng ở ngày thứ 4 được vì ở ngày thứ 4 hạt giống cuối mới bắt đầu
   được trồng, nên sang ngày thứ 5 nó mới được trồng xong
   => lúc này ta tìm max mới là chính xác


* Cách làm ở file trong_cay.cpp chỉ áp dụng cho dữ liệu đầu vào với n nhỏ vì dùng for lồng nhau
* Khi với n lớn thì không pass được bộ test của kattis
=> Ta cần nhìn vào từng ngày để suy ra công thức nhanh
4 3 3 2
Sau 5 ngày còn:
1 1 2 2

=> 4 - 3 = 1
=> 3 - 2 = 1
=> 3 - 1 = 2
=> 2 - 0 = 2

=> Xem file pro_vjp