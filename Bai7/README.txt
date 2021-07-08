Input:
5
7 9     // Công việc thứ 1
2 4     // Công việc thứ 2
1 3     // Công việc thứ 3
1 6     // Công việc thứ 4
3 7     // Công việc thứ 5

Output:
3

Hãy xem mô tả ở hình mo_ta.png
=> Dãy công việc lớn nhất mà không có công việc nào chồng nhau là 3, 5, 1 (dãy công việc có tổng số công việc là 3)
=> Để tìm được dãy này trước tiên ta cần sắp xếp dãy công việc theo
   chiều tăng dần của thời gian kết thúc:
   1 3
   2 4
   1 6
   3 7
   7 9

* Ta bắt đầu với công việc đầu tiên (1 3) thời gian kết thúc cv tại 3
=> Chọn tiếp được công việc (3 7) vì thời gian bắt đầu của công việc này là tại 3 (3 >= thời gian kết thúc cv phía trước)
   thời gian kết thúc cv tiếp theo này tại 7
=> Chọn tiếp được công việc (7 9) vì thời gian bắt đầu của công việc này là tại 7 (7 >= thời gian kết thúc cv phía trước)
   thời gian kết thúc cv tại 9
=> Đã duyệt hết khả năng với công việc bắt đầu là (1, 3) => dãy có 3 công việc

* Tiếp theo ta lặp lại với dãy công việc bắt đầu tại (2 4)
=> Tương tự ta có dãy công việc (2 4) (7 9) => dãy có 2 công việc (nhỏ hơn dãy phía trên với 3 công việc) => loại

* Lặp lại đến hết

=> Vậy dãy công việc lớn nhất là (1 3) (3 7) (7 9) với 3 công việc

