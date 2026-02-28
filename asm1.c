/******************************************************************************
 * Họ và tên: [ĐIỀN TÊN TẠI ĐÂY]
 * MSSV:      [ĐIỀN MSSV TẠI ĐÂY]
 * Lớp:       [ĐIỀN LỚP TẠI ĐÂY]
 *****************************************************************************/

// Tạo file asm2.c và hoàn thiện nội dung Assignment từ nội dung file asm1.c


// Danh sách các chức năng trong ASM1:
// 1. Chức năng số 1: Kiểm tra số nguyên
// 2. Chức năng số 2. Tìm Ước số chung và bội số chung của 2 số 
// 3. Chức năng số 3: Chương trình tính tiền cho quán Karaoke
// 4. Chức năng số 4: Tính tiền điện 
// 5. Chức năng số 5: Chức năng đổi tiền 
// 6. Chức năng số 6: Xây dựng chức năng tính lãi suất vay ngân hàng vay trả góp 
// 7. Chức năng số 7: Xây dựng chương trình vay tiền mua xe
// 8. Chức năng số 8: Sắp xếp thông tin sinh viên
// 9. Chức năng số 9: Xây dựng game FPOLY-LOTT
// 10. Chức năng số 10: Xây dựng chương trình tính toán phân số 
// Viết chương trình C thực hiện các chức năng trên

#include <stdio.h>
#include <math.h>

// ====== CASE 1: HÀM KIỂM TRA SỐ ======
void kiemTraSo()
{
    float n;
    printf("Nhap mot so bat ky: ");
    scanf("%f", &n);

    // 1. Kiểm tra số nguyên
    if (n != (int)n)
    {
        printf("%.2f khong phai la so nguyen.\n", n);
    }
    else
    {
        int x = (int)n;
        printf("%d la so nguyen.\n", x);

        // 2. Kiểm tra số nguyên tố
        int laNguyenTo = 1;
        if (x < 2)
        {
            laNguyenTo = 0;
        }
        else
        {
            for (int i = 2; i * i <= x; i++)
            {
                if (x % i == 0)
                {
                    laNguyenTo = 0;
                    break;
                }
            }
        }

        if (laNguyenTo)
            printf("%d la so nguyen to.\n", x);
        else
            printf("%d khong phai la so nguyen to.\n", x);

        // 3. Kiểm tra số chính phương
        int can = (int)sqrt(x);
        if (can * can == x)
            printf("%d la so chinh phuong.\n", x);
        else
            printf("%d khong phai la so chinh phuong.\n", x);
    }
}

// ===== HÀM TÌM Ước chung lớn nhất =====
int timUCLN(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// ===== HÀM TÌM Bội số chung nhỏ nhất =====
int timBCNN(int a, int b)
{
    int ucln = timUCLN(a, b);
    return (a * b) / ucln;
}

// ===== HÀM CHÍNH CASE 2: Tìm Ước số chung và bội số chung của 2 số =====
void uocBoiChung()
{
    int x, y;
    printf("Nhap hai so nguyen x va y: ");
    scanf("%d %d", &x, &y);

    if (x == 0 || y == 0)
    {
        printf("Khong the tinh UCLN va BCNN khi mot trong hai so bang 0.\n");
        return;
    }

    int ucln = timUCLN(x, y);
    int bcnn = timBCNN(x, y);

    printf("Uoc so chung lon nhat (UCLN) cua %d va %d la: %d\n", x, y, ucln);
    printf("Boi so chung nho nhat (BCNN) cua %d va %d la: %d\n", x, y, bcnn);
}

// ===== CASE 3: TÍNH TIỀN KARAOKE =====
void tinhTienKaraoke()
{
    float gioBatDau, gioKetThuc;
    float tongTien = 0;

    printf("Nhap gio bat dau (12-23): ");
    scanf("%f", &gioBatDau);
    printf("Nhap gio ket thuc (12-23): ");
    scanf("%f", &gioKetThuc);

    // Kiểm tra hợp lệ
    if (gioBatDau < 12 || gioKetThuc > 23 || gioBatDau >= gioKetThuc)
    {
        printf("Thoi gian khong hop le! Quan chi hoat dong tu 12h den 23h va gio ket thuc phai lon hon gio bat dau.\n");
    }
    else
    {
        float soGio = gioKetThuc - gioBatDau;

        if (soGio <= 3)
        {
            tongTien = soGio * 150000;
        }
        else
        {
            tongTien = 3 * 150000 + (soGio - 3) * 150000 * 0.7; // giảm 30% sau 3 giờ
        }

        // Giảm 10% nếu bắt đầu trong khung 14h–17h
        if (gioBatDau >= 14 && gioBatDau <= 17)
        {
            tongTien *= 0.9;
            printf("Ap dung giam 10%% vi bat dau trong khoang 14h - 17h.\n");
        }

        printf("So gio hat: %.2f\n", soGio);
        printf("Tong tien phai tra: %.0f VND\n", tongTien);
    }
}

// ===== Case 4: Tính tiền điện =====
void tinhTienDien()
{
    float kwh, tien = 0;
    printf("Nhap so dien su dung (kWh): ");
    scanf("%f", &kwh);

    if (kwh < 0)
    {
        printf("So dien khong hop le!\n");
        return;
    }

    if (kwh <= 50)
        tien = kwh * 1678;
    else if (kwh <= 100)
        tien = 50 * 1678 + (kwh - 50) * 1734;
    else if (kwh <= 200)
        tien = 50 * 1678 + 50 * 1734 + (kwh - 100) * 2014;
    else if (kwh <= 300)
        tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kwh - 200) * 2536;
    else if (kwh <= 400)
        tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kwh - 300) * 2834;
    else
        tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kwh - 400) * 2927;

    printf("So tien phai tra: %.0f VND\n", tien);
}

// ===== Case 5: Đổi tiền =====
void doiTien()
{
    int soTien;
    printf("Nhap so tien can doi: ");
    scanf("%d", &soTien);

    if (soTien <= 0)
    {
        printf("So tien phai lon hon 0.\n");
        return; // ✅ dùng return thay vì break
    }

    // Mảng mệnh giá tiền (đơn vị: nghìn đồng)
    int menhGia[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int soTo[9] = {0}; // lưu số tờ tương ứng với từng mệnh giá

    int tienConLai = soTien;

    printf("\nSo tien %d duoc doi thanh:\n", soTien);

    // Tính số tờ từng mệnh giá
    for (int i = 0; i < 9; i++)
    {
        soTo[i] = tienConLai / menhGia[i];
        tienConLai = tienConLai % menhGia[i];
    }

    // In kết quả
    for (int i = 0; i < 9; i++)
    {
        if (soTo[i] > 0)
        {
            printf("%d to menh gia %d\n", soTo[i], menhGia[i]);
        }
    }
}

// ===== Case 6: Tính lãi suất vay ngân hàng vay trả góp =====
void tinhLaiSuatVay()
{
    float tienVay;
    const float laiSuat = 0.05; // 5%/tháng
    const int soThang = 12;

    printf("Nhap so tien muon vay: ");
    scanf("%f", &tienVay);

    if (tienVay <= 0)
    {
        printf("So tien vay phai lon hon 0.\n");
        return;
    }

    float gocPhaiTraMoiThang = tienVay / soThang;
    float tienConLai = tienVay;

    printf("\n%-10s %-15s %-15s %-15s %-15s\n",
           "Ky han", "Lai phai tra", "Goc phai tra", "Tong tra", "So tien con lai");
    printf("---------------------------------------------------------------\n");

    for (int thang = 1; thang <= soThang; thang++)
    {
        float laiPhaiTra = tienConLai * laiSuat;
        float tongTra = laiPhaiTra + gocPhaiTraMoiThang;
        tienConLai -= gocPhaiTraMoiThang;

        printf("%-10d %-15.0f %-15.0f %-15.0f %-15.0f\n",
               thang, laiPhaiTra, gocPhaiTraMoiThang, tongTra, tienConLai);
    }
}

// ===== Case 7: Vay tiền mua xe =====
void vayMuaXe()
{
    const float giaXe = 500000000; // 500 triệu
    const int soNam = 24;
    const int soThang = soNam * 12;
    const float laiSuatNam = 0.072;             // 7.2%/năm
    const float laiSuatThang = laiSuatNam / 12; // 0.6%/tháng

    float phanTramVay;
    printf("Nhap phan tram vay toi da (vi du: 80 nghia la vay 80%% gia tri xe): ");
    scanf("%f", &phanTramVay);

    if (phanTramVay <= 0 || phanTramVay > 100)
    {
        printf("Phan tram vay khong hop le!\n");
        return;
    }

    float soTienVay = giaXe * (phanTramVay / 100);
    float traTruoc = giaXe - soTienVay;

    float gocPhaiTraMoiThang = soTienVay / soThang;
    float tienConLai = soTienVay;

    printf("\n=== THONG TIN VAY MUA XE ===\n");
    printf("Gia xe: %.0f VND\n", giaXe);
    printf("Tra truoc: %.0f VND\n", traTruoc);
    printf("So tien vay: %.0f VND\n", soTienVay);
    printf("Ky han: %d nam (%d thang)\n", soNam, soThang);
    printf("Lai suat co dinh: 7.2%%/nam (%.2f%%/thang)\n\n", laiSuatThang * 100);

    printf("%-8s %-15s %-15s %-15s %-15s\n",
           "Thang", "Lai phai tra", "Goc phai tra", "Tong tra", "Con lai");
    printf("--------------------------------------------------------------------------\n");

    for (int thang = 1; thang <= soThang; thang++)
    {
        float laiPhaiTra = tienConLai * laiSuatThang;
        float tongTra = laiPhaiTra + gocPhaiTraMoiThang;
        tienConLai -= gocPhaiTraMoiThang;

        printf("%-8d %-15.0f %-15.0f %-15.0f %-15.0f\n",
               thang, laiPhaiTra, gocPhaiTraMoiThang, tongTra, tienConLai);
    }

    printf("\n==> So tien tra truoc: %.0f VND\n", traTruoc);
    printf("==> So tien phai tra hang thang (thang dau tien): ~%.0f VND\n",
           gocPhaiTraMoiThang + (soTienVay * laiSuatThang));
}
// ===== Case 8: Sap xep sinh vien theo diem =====
void sapXepSinhVien()
{
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar(); // bỏ ký tự Enter sau khi nhập số

    char ten[n][50];
    float diem[n];

    // Nhập thông tin sinh viên
    for (int i = 0; i < n; i++)
    {
        printf("\nNhap ten sinh vien thu %d: ", i + 1);
        fgets(ten[i], sizeof(ten[i]), stdin);
        ten[i][strcspn(ten[i], "\n")] = '\0'; // xóa dấu xuống dòng

        printf("Nhap diem: ");
        scanf("%f", &diem[i]);
        getchar();
    }

    // Sắp xếp điểm giảm dần
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (diem[i] < diem[j])
            {
                // Hoán đổi điểm
                float tempDiem = diem[i];
                diem[i] = diem[j];
                diem[j] = tempDiem;

                // Hoán đổi tên tương ứng
                char tempTen[50];
                strcpy(tempTen, ten[i]);
                strcpy(ten[i], ten[j]);
                strcpy(ten[j], tempTen);
            }
        }
    }

    // Hiển thị kết quả
    printf("\n=== DANH SACH SINH VIEN (GIAM DAN THEO DIEM) ===\n");
    printf("%-25s %-10s %-15s\n", "Ho ten", "Diem", "Hoc luc");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < n; i++)
    {
        char hocLuc[20];
        if (diem[i] >= 9.0)
            strcpy(hocLuc, "Xuat sac");
        else if (diem[i] >= 8.0)
            strcpy(hocLuc, "Gioi");
        else if (diem[i] >= 6.5)
            strcpy(hocLuc, "Kha");
        else if (diem[i] >= 5.0)
            strcpy(hocLuc, "Trung binh");
        else
            strcpy(hocLuc, "Yeu");

        printf("%-25s %-10.2f %-15s\n", ten[i], diem[i], hocLuc);
    }
}

// ===== Case 9: Game FPOLY-LOTT =====
void gameFPOLY_LOTT()
{
    int so1, so2;
    int random1, random2;
    int trung = 0;

    // Tạo bộ sinh số ngẫu nhiên
    srand(time(NULL));

    printf("Nhap 2 so tu 1 den 15 (cach nhau boi dau cach): ");
    scanf("%d %d", &so1, &so2);

    // Kiểm tra hợp lệ
    if (so1 < 1 || so1 > 15 || so2 < 1 || so2 > 15)
    {
        printf("Chi duoc nhap cac so tu 1 den 15!\n");
        return;
    }

    // Sinh ngẫu nhiên 2 số từ 1 đến 15 (không trùng nhau)
    random1 = rand() % 15 + 1;
    do
    {
        random2 = rand() % 15 + 1;
    } while (random2 == random1);

    printf("\n=== Ket qua quay so FPOLY-LOTT ===\n");
    printf("So may man: %02d va %02d\n", random1, random2);

    // Kiểm tra trúng
    if (so1 == random1 || so1 == random2)
        trung++;
    if (so2 == random1 || so2 == random2)
        trung++;

    // Hiển thị kết quả
    if (trung == 2)
        printf("🎉 Chuc mung ban da TRUNG GIAI NHAT!\n");
    else if (trung == 1)
        printf("🎊 Chuc mung ban da TRUNG GIAI NHI!\n");
    else
        printf("😅 Chuc ban may man lan sau!\n");
}

// ===== Case 10: Tinh phan so  =====
void tinhPhanSo()
{
    int tu1, mau1, tu2, mau2;
    printf("Nhap phan so thu nhat (dang tu mau): ");
    scanf("%d %d", &tu1, &mau1);
    printf("Nhap phan so thu hai (dang tu mau): ");
    scanf("%d %d", &tu2, &mau2);

    if (mau1 == 0 || mau2 == 0)
    {
        printf("Mau so khong duoc bang 0!\n");
        return;
    }

    // Tính toán
    int tong_tu = tu1 * mau2 + tu2 * mau1;
    int tong_mau = mau1 * mau2;

    int hieu_tu = tu1 * mau2 - tu2 * mau1;
    int hieu_mau = mau1 * mau2;

    int tich_tu = tu1 * tu2;
    int tich_mau = mau1 * mau2;

    int thuong_tu = tu1 * mau2;
    int thuong_mau = mau1 * tu2;

    // In kết quả
    printf("\n=== KET QUA ===\n");
    printf("Tong:   %d/%d\n", tong_tu, tong_mau);
    printf("Hieu:   %d/%d\n", hieu_tu, hieu_mau);
    printf("Tich:   %d/%d\n", tich_tu, tich_mau);
    printf("Thuong: %d/%d\n", thuong_tu, thuong_mau);
}

int main()
{
    int chonChucNang;
    do
    {
        printf("Chon chuc nang:\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Tim Uoc so chung va boi so chung cua 2 so\n");
        printf("3. Tinh tien cho quan Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Chuc nang doi tien\n");
        printf("6. Tinh lai suat vay ngan hang vay tra gop\n");
        printf("7. Vay tien mua xe\n");
        printf("8. Sap xep thong tin sinh vien\n");
        printf("9. Game FPOLY-LOTT\n");
        printf("10. Tinh toan phan so\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &chonChucNang);

        switch (chonChucNang)
        {
        case 1:
            // Gọi hàm kiểm tra số nguyên
            printf("DA CHON CHUC NANG 1: KIEM TRA SO NGUYEN\n");
            kiemTraSo();
            break;
        case 2:
            // Gọi hàm tìm Ước số chung và bội số chung
            printf("DA CHON CHUC NANG 2: TIM UOC SO CHUNG VA BOI SO CHUNG CUA 2 SO\n");
            uocBoiChung();
            break;
        case 3:
            // Gọi hàm tính tiền cho quán Karaoke
            printf("DA CHON CHUC NANG 3: TINH TIEN CHO QUAN KARAOKE\n");
            tinhTienKaraoke();
            break;
        case 4:
            // Gọi hàm tính tiền điện
            printf("DA CHON CHUC NANG 4: TINH TIEN DIEN\n");
            tinhTienDien();
            break;
        case 5:
            // Gọi hàm đổi tiền
            printf("DA CHON CHUC NANG 5: DOI TIEN\n");
            doiTien();
            break;
        case 6:
            // Gọi hàm tính lãi suất vay ngân hàng
            printf("DA CHON CHUC NANG 6: TINH LAI SUAT VAY NGAN HANG VAY TRA GOP\n");
            tinhLaiSuatVay();
            break;
        case 7:
            // Gọi hàm vay tiền mua xe
            printf("DA CHON CHUC NANG 7: VAY TIEN MUA XE\n");
            vayMuaXe();
            break;
        case 8:
            // Gọi hàm sắp xếp thông tin sinh viên
            printf("DA CHON CHUC NANG 8: SAP XEP THONG TIN SINH VIEN\n");
            sapXepSinhVien();
            break;
        case 9:
            // Gọi hàm game FPOLY-LOTT
            printf("DA CHON CHUC NANG 9: GAME FPOLY-LOTT\n");
            gameFPOLY_LOTT();
            break;
        case 10:
            // Gọi hàm tính toán phân số
            printf("DA CHON CHUC NANG 10: TINH TOAN PHAN SO\n");
            tinhPhanSo();
            break;
        case 0:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (chonChucNang != 0);

    return 0;
}