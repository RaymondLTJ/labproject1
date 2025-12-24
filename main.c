#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#ifdef _WIN32
    #define CLEAR "cls"
    #include <windows.h>
#else
    #define CLEAR "clear"
    #include <unistd.h>
#endif

//deklarasi fungsi

//fungsi pelengkap
void identify_player (char player[100]);
void jeda_dan_hapus();
int input_valid(int min, int max);
void delay();
void delay_custom(int x);
int cek_benar(int hasil);
int random_num();
void bubble_sort(int arr[], int n);
void bubble_sort_lb(char nama[][20], int attempt[], int n);
int linear_search (int arr[], int n, int target);
void jeda();
int random_num_char();
int random_char();

//fungsi leaderboard
void show_leaderboard();
void save_leaderboard(char nama[], int attempt);

//fungsi narasi
void narasip1();
void narasip2();
void narasip3();
void narasi1_1(int pertama1, int *attempt);
void narasi1_2(int pertama2, int *attempt);
void narasi1_3(int pertama3, int *attempt);
void narasi2_1(int pertama1, int *attempt);
void narasi2_2(int pertama2, int *attempt);
void narasi2_3(int pertama3, int *attempt);
void narasi3_1(int pertama1, int *attempt);
void narasi3_2(int pertama2, int *attempt);
void narasi3_3(int pertama3, int *attempt);

//fungsi pintu
int pintu1_1(int pertama1, int *attempt);
int pintu1_2(int pertama2, int *attempt);
int pintu1_3(int pertama3, int *attempt);
void pintu1ed();
int pintu2_1(int pertama1, int *attempt);
int pintu2_2(int pertama2, int *attempt);
int pintu2_3(int pertama3, int *attempt);
void pintu2ed();
int pintu3_1(int pertama1, int *attempt);
int pintu3_2(int pertama2, int *attempt);
int pintu3_3(int pertama3, int *attempt);
void pintu3ed();
void narasiend(int *attempt);

//isi fungsi
void identify_player (char player[100]){
	while(1){
	if (strlen(player) > 10 ){
		printf ("\nKarakter lebih dari 10!\n\n");
		printf ("Nama: "); scanf (" %[^\n]", player);
	}
	else{
		printf ("\nHalo, %s!\n", player);
		printf ("Memulai permainan...\n");
		delay();
		break;
		}
	}
}

void delay(){
	#ifdef _WIN32
    	Sleep(1500);
	#else
    	usleep(1500 * 1000); // mac
	#endif
}	

void delay_custom(int x){
	#ifdef _WIN32
    	Sleep(x);
	#else
    	usleep(x * 1000); // mac
	#endif
}	

void jeda_dan_hapus() {
    printf("\nTekan apa saja untuk melanjutkan...");
    getch(); 
    system(CLEAR);
}	

void jeda(){
	printf ("\nTekan apa saja untuk melanjutkan...");
	getch();
}

int cek_benar(int hasil){
	if (hasil == 0) {
    	jeda_dan_hapus();
        return 0; 
    }
    return 1;
}

int input_valid(int min, int max){
    int x;
    while (1){
        scanf(" %d", &x);
        if (x >= min && x <= max) return x;
        else printf("Pilihan tidak valid. Coba lagi: ");
    }
}

int random_num(){
	return rand()%9 + 1;
}

int random_char(){
	return rand()%26 + 'a';
}

int random_num_char(){
	return rand()%10 +'0';
}

void bubble_sort(int arr[], int n){
    for(int i = 0; i < n -1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubble_sort_lb(char nama[][20], int attempt[], int n){
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (attempt[j] > attempt[j + 1]) {
                int temp_attempt = attempt[j];
                attempt[j] = attempt[j + 1];
                attempt[j + 1] = temp_attempt;
                char temp_nama[20];
                strcpy(temp_nama, nama[j]);
                strcpy(nama[j], nama[j + 1]);
                strcpy(nama[j + 1], temp_nama);
            }
        }
    }	
}

int linear_search(int arr[], int n, int target){
    for(int i = 0; i < n; i++){
        if(arr[i] == target)
            return i;
    }
    return -1;
}

void show_leaderboard(){
    FILE *fp = fopen("leaderboard.txt", "r");
    if (fp == NULL) {
        printf("Leaderboard masih kosong.\n");
        return;
    }
    
    char nama[100][20];
    int attempt[100];
    int count = 0;
    
    printf ("Leaderboard (Dari attempt terendah)\n");
    printf ("====================================\n");
    
	while (fscanf(fp, "%s %d", nama[count], &attempt[count]) != EOF) {
    		count++;
	}
    fclose(fp);
    
    bubble_sort_lb(nama, attempt, count);
    for (int i = 0; i < count; i++){
    	printf("%d. %s | %d attempt(s)\n", i+1, nama[i], attempt[i]);
	}
    
}

void save_leaderboard(char nama[], int attempt){
    FILE *fp = fopen("leaderboard.txt", "a");
    if (fp == NULL) {
        printf("Gagal buka leaderbord.\n");
        return;
    }

    fprintf(fp, "%s %d\n", nama, attempt);
    fclose(fp);	
}

void narasip1(){
	printf ("Kamu terbangun dengan denyut sakit yang menghantam kepalamu seperti palu.\n\n");
	delay();
	printf ("Kamu melihat-lihat tempat sekitarmu dan bertanya-tanya..\n\n");
	delay();	
	printf ("\"Gedung apa ini? Apa yang baru saja terjadi?\", gumam dirimu dalam hati.\n\n");
	delay();
	printf ("Kamu pun berkeliling-keliling gedung aneh tersebut dengan penuh rasa kebingungan.\n\n");
	delay();
	printf ("Akhirnya, kamu memutuskan untuk masuk ke satu pintu yang tersedia di gedung tersebut.\n\n");
}

void narasip2(){
	printf ("Kamu merasa lega telah melewati rintangan di pintu tersebut.\n\n");
	delay();
	printf ("Merasa tidak ada lagi rintangan, kamu berjalan-jalan dengan hati yang bahagia.\n\n");
	delay();
	printf ("Namun... di depanmu terlihat satu pintu baru yang terasa.... intimidatif..\n\n");
	delay();
	printf ("Berharap bisa keluar, kamu mencoba masuk ke pintu tersebut.\n");
}

void narasip3(){
	printf ("Kamu akhirnya mencapai akhir perjalanan...\n");
	delay();
	printf ("Atau itu yang kamu kira.\n");
	delay();
	printf ("Di depanmu, terdapat sebuah pintu lagi.\n");
	delay();
	printf ("Kamu membuka pintu tersebut secara perlahan.\n\n");
	delay();
	printf ("Tiba-tiba, muncul sebuah sosok yang menyeramkan.\n\n");
	delay();
	printf ("Di hadapanmu, Ia berkata:\n");
	delay();
	printf ("\"Selamat datang di duniaku, wahai anak muda.\"\n");
	delay();
	printf ("\"Jika kamu ingin keluar dari duniaku, sebut ulang 3 hal yang akan aku ucapkan.\"\n");
	delay();
	printf ("\"Jika semua benar, kamu boleh pergi dari sini.\"\n\n");
}

void narasi1_1(int pertama1, int *attempt){
	if (pertama1 == 1){
    	printf("=== RUANGAN 1 : DADU TAKDIR ===\n");
    	printf ("                                                                          Attempt: %d\n", *attempt);
    	delay();
    	printf("Kamu melangkah ke dalam ruangan yang sunyi.\n");
    	delay();
    	printf("Udara terasa berat, seolah ruangan ini menahan napas.\n\n");
		delay();	
    	printf("Di tengah lantai, sebuah dadu batu raksasa melayang perlahan.\n");
    	delay();
    	printf("Saat kamu mendekat, dadu itu jatuh dengan dentuman keras.\n\n");
		delay();
    	printf("Tulisan samar muncul di dinding:\n");
    	delay();
    	printf("\"Lempar dadu dan tentukan nasibmu...\"\n\n");
    	delay();
	}
	
	else{
		printf("=== RUANGAN 1 : DADU TAKDIR ===\n");
		printf ("                                                                          Attempt: %d\n", *attempt);
		printf("Tulisan samar muncul di dinding:\n");
		printf("\"Lempar dadu dan tentukan nasibmu...\"\n\n");
		printf ("Kamu tahu apa yang harus dilakukan.\n");
	}
    printf("1. Lempar dadu\n");
    printf("2. Mundur\n");
    printf("Pilihanmu: ");
}

void narasi1_2(int pertama2, int *attempt){
	if (pertama2 == 1){
		printf("=== RUANGAN 2 : PETI MISTERIUS ===\n");
		printf ("                                                                          Attempt: %d\n", *attempt);
		delay();
    	printf ("Kamu memasuki ruangan selanjutnya dan melihat suatu hal yang aneh\n");
    	delay();
    	printf("Tiga peti berdiri sejajar di hadapanmu.\n");
    	delay();
    	printf("Bentuknya sama. Ukurannya sama.\n");
    	delay();
    	printf("Namun... perasaanmu berkata sebaliknya.\n\n");
		delay();
    	printf("Tulisan di dinding bergetar:\n");
    	delay();
    	printf("\"Instingmu lebih berharga dari logika.\"\n\n");
    	delay();

	}
	else{
		printf("=== RUANGAN 2 : PETI MISTERIUS ===\n");
		printf ("                                                                          Attempt: %d\n", *attempt);
    	printf("Tulisan di dinding bergetar:\n");
    	printf("\"Instingmu lebih berharga dari logika.\"\n\n");
    	printf ("Kamu tahu apa yang harus dilakukan\n");
	}

    printf("1. Buka peti kiri\n");
    printf("2. Buka peti tengah\n");
    printf("3. Buka peti kanan\n");
    printf("Pilihanmu: ");
}

void narasi1_3(int pertama3, int *attempt){
	if (pertama3 == 1){
		printf("=== RUANGAN 3 : LEMPARAN TERAKHIR ===\n");
    	printf ("                                                                          Attempt: %d\n", *attempt);
    	delay();
		printf("Ruangan terakhir terasa lebih tenang...\n");
		delay();
    	printf("Terlalu tenang.\n\n");
		delay();
    	printf("Sebuah koin emas melayang di udara.\n");
    	delay();
    	printf("Cahaya memantul di permukaannya.\n\n");
		delay();
    	printf("Tulisan terakhir muncul:\n");
    	delay();
    	printf("\"Satu pilihan. Satu kesempatan.\"\n\n");
    	delay();
	}
	else{
		printf("=== RUANGAN 3 : LEMPARAN TERAKHIR ===\n");
    	printf ("                                                                          Attempt: %d\n", *attempt);
    	printf("Sebuah koin emas melayang di udara.\n");
    	printf("Cahaya memantul di permukaannya.\n\n");
    	printf("Tulisan terakhir muncul:\n");
    	printf("\"Satu pilihan. Satu kesempatan.\"\n\n");		
    	printf("Kamu tahu apa yang harus dilakukan\n");		
	}

    printf("1. Heads\n");
    printf("2. Tails\n");
    printf("Pilihanmu: ");

}

void narasi2_1(int pertama1, int *attempt){
	if (pertama1 == 1){
		printf("=== RUANGAN 4 : SUSUNAN MISTERIUS ===\n");
		printf ("                                                                          Attempt: %d\n", *attempt);
		delay();
	    printf("Kamu memasuki ruangan batu yang dipenuhi ukiran simbol kuno.\n");	
		delay();
    	printf("Di hadapanmu terdapat lima lempeng batu, masing-masing memancarkan cahaya redup.\n");
    	delay();
		printf("Di atas setiap lempeng tertulis sebuah pertanyaan pertanyaan sederhana.\n");
    	delay();
		printf("Sebuah suara bergema di kepalamu:\n\n");
    	delay();
		printf("\"Jawaban adalah kunci. Urutan adalah jalan.\"\n");
    	delay();
		printf("\"Susun hasilnya dari yang TERKECIL hingga TERBESAR untuk melanjutkan.\"\n\n");
    	delay();
		printf("1. 7^2 - 7\n2. Angka jika digabungkan menjadi huruf B\n3. Angka Keberuntungan\n4. (23 + 10 - 22) * (2^3)\n5. 62537^0\n\n");
    	delay();
	}
	else{
		printf("=== RUANGAN 4 : SUSUNAN MISTERIUS ===\n");
		printf ("                                                                          Attempt: %d\n", *attempt);
    	printf("\"Jawaban adalah kunci. Urutan adalah jalan.\"\n");
    	printf("\"Susun hasilnya dari yang TERKECIL hingga TERBESAR untuk melanjutkan.\"\n\n");
    	printf("1. 7^2 - 7\n2. Angka jika digabungkan menjadi huruf B\n3. Angka Keberuntungan\n4. (23 + 10 - 22) * (2^3)\n5. 62537^0\n\n");
    	printf ("Kamu tahu apa yang harus dilakukan\n");
	}
	printf("Urutkan : ");
}

void narasi2_2(int pertama2, int *attempt){
	if (pertama2 == 1){
		printf("=== RUANGAN 5 : BUKU TAKDIR ===\n");
		printf ("                                                                          Attempt: %d\n", *attempt);
		delay();
		printf("Kamu memasuki ruangan yang dipenuhi dengan buku.\n");
		delay();
    	printf("Saat kamu berada ditengah ruangan beberapa buku menyala dan muncul tulisan didinding.\n\n");
    	delay();
    	printf("Hanya 1 buku yang dapat membawamu lanjut ke pintu berikutnya. pilihlah.\n\n");
    	delay();
    	printf("43.Pengantar Aritmatika Dasar.\n41.Logika dan Paradoks Kuno\n18.Identitas Matematika Sederhana\n67.Geometri Ruang dan Dimensi\n1.Statistika untuk Pemula\n\n");
    	delay();
    	printf("Aku bukan tentang menghitung banyaknya,\n");
    	delay();
		printf ("bukan pula tentang bentuk atau peluang.\n");
		delay();
		printf ("bukan pula tentang bentuk atau peluang.\n");
		delay();
		printf ("bukan pula tentang bentuk atau peluang.\n");
		delay();
		printf ("Aku menyederhanakan yang rumit,\n");
		delay();
		printf ("menyatukan ruas kiri dan kanan menjadi sama\n\n");
		delay();
		printf ("Pilih 1 buku: ");
		delay();
	}
	else{
		printf("=== RUANGAN 5 : BUKU TAKDIR ===\n");
		printf ("                                                                          Attempt: %d\n", *attempt);
		printf("Hanya 1 buku yang dapat membawamu lanjut ke pintu berikutnya. pilihlah.\n\n");
    	printf("43.Pengantar Aritmatika Dasar.\n41.Logika dan Paradoks Kuno\n18.Identitas Matematika Sederhana\n67.Geometri Ruang dan Dimensi\n1.Statistika untuk Pemula\n\n");
    	printf("Aku bukan tentang menghitung banyaknya,\n");
		printf("bukan pula tentang bentuk atau peluang.\n");
		printf("bukan pula tentang bentuk atau peluang.\n");
		printf("bukan pula tentang bentuk atau peluang.\n");
		printf("Aku menyederhanakan yang rumit,\n");
		printf("menyatukan ruas kiri dan kanan menjadi sama\n\n");
		printf("Kamu tahu apa yang harus dilakukan\n");
		printf("Pilih 1 buku: ");
	}	
}

void narasi2_3(int pertama3, int *attempt){
	if (pertama3 == 1){
		printf ("=== RUANGAN 6 : GABUNG? ===\n");
		printf ("                                                                          Attempt: %d\n", *attempt);
    	printf("Kamu memasuki ruangan kosong.\n\n");
    	printf("Lalu tiba tiba tulisan muncul di dinding...\n");
    	printf("Inilah tantangan terakhirmu:\n");
		printf("Gabungkan 2 jawaban di pintu sebelumnya menjadi 1 list yang tersusun\n\n");		
	}
	else{
		printf ("=== RUANGAN 6 : GABUNG? ===\n");
		printf ("                                                                          Attempt: %d\n", *attempt);
    	printf("Inilah tantangan terakhirmu:\n");
		printf ("Gabungkan 2 jawaban di pintu sebelumnya menjadi 1 list yang tersusun\n\n");
    	printf("Kamu tahu apa yang harus dilakukan\n");
	}	
	printf("Jawabanmu: ");
}

void narasi3_1(int pertama1, int *attempt){
	if (pertama1 == 1){
		printf("=== RUANGAN ? : HAFALAN MALAPETAKA ===\n");
    	printf ("                                                                          Attempt: %d\n", *attempt);
    	delay();
    	printf ("\"Siapkan dirimu, wahai anak muda.\"\n");
    	delay();
    	printf ("\"Karena, hanya keberanian dan kecerdikan yang akan menang di sini.\"\n");
    	delay();
    	printf ("\"Mari kita pemanasan terlebih dahulu, WAHAHAHAHA!\"\n\n");	
	}
	else{
		printf("=== RUANGAN ? : HAFALAN MALAPETAKA ===\n");
    	printf ("                                                                          Attempt: %d\n", *attempt);
    	printf ("\"Siapkan dirimu, wahai anak muda.\"\n");
    	printf ("\"Karena, hanya keberanian dan kecerdikan yang akan menang di sini.\"\n");
    	printf ("\"Mari kita pemanasan terlebih dahulu, WAHAHAHAHA!\"\n\n");
	}
}

void narasi3_2(int pertama2, int *attempt){
	if (pertama2 == 1){
		printf("=== RUANGAN ?: HAFALAN MALAPETAKA ===\n");
		printf("                                                                          Attempt: %d\n", *attempt);
		delay();
		printf("Boleh juga...\n");
		delay();
		printf("\"Tapi jangan terlalu percaya diri.\"\n");
		delay();
		printf ("\"Tantangan selanjutnya bisa membuat otakmu menjadi gila!\"\n");
		delay();
		printf("\"Perhatikan setiap angka dengan seksama, karena satu kesalahan bisa berakibat fatal.\"\n");
	}
	else{
		printf("=== RUANGAN ?: HAFALAN MALAPETAKA ===\n");
		printf("                                                                          Attempt: %d\n", *attempt);
		printf("\"Perhatikan setiap angka dengan seksama, karena satu kesalahan bisa berakibat fatal.\"\n");
	}
}

void narasi3_3(int pertama3, int *attempt){
	if (pertama3 == 1){
		printf("=== RUANGAN ?: HAFALAN MALAPETAKA ===\n");
		printf("                                                                          Attempt: %d\n", *attempt);	
		printf ("Wow, menakjubkan..\n");
		delay();
		printf("Selanjutnya adalah yang terakhir.\n\n");
		delay();
		printf ("Bila berhasil, kamu berhak untuk keluar.\n");
		delay();
		printf("Bila tidak, kamu akan menerima konsekuensinya.\n");
		delay();
		printf ("SELAMAT BERJUANG.\n");
		
	}
	else{
		printf("=== RUANGAN ?: HAFALAN MALAPETAKA ===\n");
		printf("                                                                          Attempt: %d\n", *attempt);
		printf("Ini adalah yang terakhir.\n");
		delay();
		printf ("Bila berhasil, kamu berhak untuk keluar.\n");
		delay();
		printf("Bila tidak, kamu akan menerima konsekuensinya.\n");
		delay();
		printf ("SELAMAT BERJUANG.\n");
	}
}

int pintu1_1(int pertama1, int *attempt){
    	narasi1_1(pertama1, attempt);
		int jawaban = input_valid(1, 2);
    	
    	if (jawaban == 2){
    		printf ("\nKamu mencoba untuk pergi keluar, tetapi roh penjaga membunuhmu, mencegahmu untuk pergi\n\n");
			return 0;
		}
    	int hasil = rand() % 6 + 1;

    	if(hasil != 1 && hasil != 6 && hasil != 3){
        	printf("\nKamu Roll %d\n", hasil);
        	printf("Kamu berhasil! Silahkan lanjut ke pintu selanjutnya.\n");
        	printf("\x1B[3m");
        	printf("Pintu di depan mu terbuka.\n\n");
        	printf("\x1B[0m");
        	return 1;
    	}else {
        	printf("\nKamu Roll %d\n", hasil);
        	printf("Kamu gagal.\n");
        	printf("\x1B[3m");
        	printf("Ruangan mulai runtuh dan kamu terbangun lagi di ruangan ini tanpa merasa terjadi apa-apa.\n\n");
        	printf("\x1B[0m");
        	return 0;
    	}
}

int pintu1_2(int pertama2, int *attempt){
    narasi1_2(pertama2, attempt);
    int jawaban = input_valid(1, 3);



    if (jawaban == 2) {
        printf("Peti ini berisi kunci emas\n");
        printf("Selamat! Gunakan kunci yang ada di dalam peti untuk lanjut ke pintu selanjutnya!\n");
        printf("Kamu membuka pintu selanjutnya dan memasuki ruangan tersebut\n");
        return 1;
    } 
    else{
        printf("Peti ini adalah mimic\n");
        printf("Mimic membunuhmu dan kamu terlempar ke ruangan awal\n");
        return 0;
    } 
}

int pintu1_3(int pertama3, int *attempt){
    narasi1_3(pertama3, attempt);    

    int hasil = rand() % 2 + 1;
    

    int jawaban = input_valid(1, 2);
    
    printf("\nKoin berputar di udara dan jatuh ke telapak tanganmu...\n");
    printf("Hasilnya adalah: %s\n", (hasil == 1) ? "Heads" : "Tails");


    if (jawaban == hasil) {
                printf("Selamat! Instingmu tajam. Kamu berhasil melewati rintangan terakhir!\n");
                return 1; 
    } else {
                printf("Sayang sekali, pilihanmu salah. Ruangan menjadi gelap...\n");
                return 0; 
    }
}

void pintu1ed(){
    printf("=== PINTU KEBERUNTUNGAN TERBUKA ===\n");
    delay();
    printf("Kamu menarik napas panjang.\n");
    delay();
    printf("Bukan karena kepintaran.\n");
    delay();
    printf("Bukan karena kekuatan.\n\n");
    delay();
    printf("Kali ini...\n");
    delay();
    printf("Keberuntungan berpihak padamu.\n");
}

int pintu2_1(int pertama1, int *attempt){
    int arr[5] = {42, 13, 7, 88, 1};
    int arrsize = sizeof(arr) / sizeof(arr[0]);
    int jawaban[5];
    int benar = 1;
    narasi2_1(pertama1, attempt);

    bubble_sort(arr, arrsize);

    for(int i = 0; i < 5; i++){
        scanf("%d", &jawaban[i]);
    }
    for(int i = 0; i < 5; i++){
        if(jawaban[i] != arr[i]){
            benar = 0;
            break;
        }
    }
    if(benar){
        printf("Selamat! Silahkan masuk ke pintu selanjutnya");
        return 1;
    }else{
        printf("Kamu salah dan semua menjadi gelap...");
        return 0;
    }

}
int pintu2_2(int pertama2, int *attempt){
    int books[5] = {43, 18, 41, 67, 1};
    int  booklen = 5;
    int target =  18;
    int pilihan;
    narasi2_2(pertama2, attempt);
    scanf("%d", &pilihan);

    if(linear_search(books, booklen, pilihan) != -1 && pilihan == target){
        printf("Saat kamu tarik buku tersebut, tiba tiba pintu didepanmu terbuka...\n");
        return 1;
    }else if (linear_search(books, booklen, pilihan) != -1 && pilihan != target){
        printf("Setelah kamu menarik buku tersebut bayangan hitam mulai menyerang mu dan semuanya menjadi gelap...\n");
        return 0;
    }else{
        printf("Kamu memilih buku yang bukan seharusnya dipilih kamu terkena kutukan dan semuanya menjadi gelap...");
        return 0;
    }
}
int pintu2_3(int pertama3, int *attempt){
    int arr[6] = {1, 7, 13, 18, 42, 88};
    int jawaban[6];
    int benar = 1;
    narasi2_3(pertama3, attempt);
    for(int i = 0; i < 6; i++){
        scanf("%d", &jawaban[i]);
    }
    for(int i = 0; i < 6; i++){
            if(jawaban[i] != arr[i]){
            benar = 0;
            break;
        }
    }
    if(benar){
        printf("Selamat kamu benar! pintu didepanmu mulai terbuka...");
        return 1;
    }else{
        printf("Kamu salah semuanya menjadi gelap...");
        return 0;
    }
}

void pintu2ed(){
	printf("=== PINTU PENALARAN TERBUKA ===\n");
	delay();
	printf("Kamu menghembuskan napas perlahan.\n");
	delay();
	printf ("Kali ini bukan karena keberuntungan..\n\n");
	delay();
	printf ("Langkahmu jitu.\n");
	delay();
	printf ("Angka-angka tunduk pada nalarmu.\n");
	delay();
	printf ("Dan urutanmu sempurna.\n\n");
	delay();
}

int pintu3_1(int pertama1, int *attempt){
	narasi3_1(pertama1, attempt);
	jeda();
	printf ("\n");
	printf ("Untuk yang pertama: ");
	int x[5] = {random_num(), random_num(),random_num(),random_num(),random_num()};
	for (int i = 0; i < 5; i++){
		printf ("%d", x[i]);
		delay_custom(500);
	}
	
	printf ("\rUntuk yang pertama: *****\n\n");
	printf ("Jawabanmu: ");
	int jawab;
	scanf ("%d", &jawab);
	
	int benar = 0;
    for (int i = 0; i < 5; i++) benar = benar * 10 + x[i];

	if (jawab == benar){
		printf ("Jawabanmu cocok dengan kata sang Pencipta!\n");
		return 1;
	}
	else{
		printf ("Jawabanmu berbeda. Sang Pencipta menghukummu dan matamu mulai kabur.\n");
		return 0;
	}
}
int pintu3_2(int pertama2, int *attempt){
	narasi3_2(pertama2, attempt);
	jeda();
	printf ("\n");
	printf ("Untuk yang kedua: ");
	int x[7] = {random_num(), random_num(),random_num(),random_num(),random_num(), random_num(),random_num()};
	for (int i = 0; i < 7; i++){
		printf ("%d", x[i]);
		delay_custom(800);
	}
	//
	printf ("\rUntuk yang kedua: *******\n\n");
	printf ("Jawabanmu: ");
	int jawab;
	scanf ("%d", &jawab);
	
	int benar = 0;
    for (int i = 0; i < 7; i++) benar = benar * 10 + x[i];

	if (jawab == benar){
		printf("Jawabanmu cocok dengan kata sang Pencipta!\n");
		return 1;		
	} 
	else{
		printf ("Jawabanmu berbeda. Sang Pencipta menghukummu dan matamu mulai kabur.\n");
		return 0;
	}
}
int pintu3_3(int pertama3, int *attempt){
	narasi3_3(pertama3, attempt);
	jeda();
	printf ("\n");
	printf ("Untuk yang terakhir: ");
	char x[9] = {random_num_char(), random_char(),random_num_char(),random_char(),random_char(), random_num_char(),random_num_char(), random_char()};
	for (int i = 0; i < 8; i++){
		printf ("%c", x[i]);
		delay_custom(800);
	}
	//
	printf ("\rUntuk yang terakhir: ********\n\n");
	printf ("Jawabanmu: ");
	char jawab[9];
	scanf (" %8s", jawab);
	int benar = 0;
	for (int i = 0; i < 8; i++){
		if (jawab[i] == x[i]) benar++;
	}
	
	if (benar == 8){
		printf("Jawabanmu cocok dengan kata sang Pencipta!\n");
		return 1;
	}
	else{
		printf ("Jawabanmu berbeda. Sang Pencipta menghukummu dan matamu mulai kabur.\n");
		return 0;
	}
}

void pintu3ed(){
	printf ("Kamu menghela napas yang panjang.\n");
	delay();
	printf ("Kamu merasa lelah, tetapi rasanya sangatlah lega.\n\n");
	delay();
	printf ("Di depanmu, sang Pencipta berkata:\n");
	delay();
	printf ("\"Kamu berhasil, anak muda.\"\n");
	delay();
	printf("\"Kecerdasanmu, ketenanganmu, dan tekadmu telah membawamu sejauh ini.\"\n\n");
	delay();
	printf ("Cahaya mulai redup, dinding-dinding mulai runtuh, kamu mulai terjatuh pingsan.\n");
	delay();
	printf ("Sang Pencipta bergumam untuk terakhir kalinya:\n");
	delay();
	printf ("\"Kamulah sang pemenang baru..\"\n\n");
	delay();
}

void narasiend(int *attempt){
	printf ("==============================================\n");
	printf ("Selamat! Kamu telah menyelesaikan permainan ini\n");
	printf ("Jumlah attempt: %d\n", *attempt);
	printf ("==============================================\n");
}
//MAIN (ALUR GAME)
int main(){
	while (1){
	//starting point game
	printf ("======================\n");
	printf (" Short Narrative Game \n");
	printf ("======================\n\n");
	
	printf ("1. Start\n");
	printf ("2. Leaderboard\n");
	printf ("3. Exit\n\n");
	int starter;
	scanf (" %d", &starter);
	int attempt = 1;	
	switch (starter){
		case 1:{
			system(CLEAR);
			srand(time(NULL));
			printf ("Selamat datang di Short Narrative Game\n");
			printf ("Pertama, kenalkan dirimu (maks 10 kata)\n\n");
			
			//identify nama karakter
			char nama[100]; 
			printf ("Nama: "); scanf (" %[^\n]", nama);
			identify_player(nama);
			system(CLEAR);
			printf ("=== Short Narrative Game ===\n\n");
			
			narasip1();
			
			jeda_dan_hapus();
			
			//mulai game inti
			int pertama1 = 1;
			int pertama2 = 1;
			int pertama3 = 1;
			int hasil_pintu;
			
			//pintu 1 checkpoint
			while(1){
        		hasil_pintu = pintu1_1(pertama1, &attempt);
        		pertama1 = 0;
				if (!cek_benar(hasil_pintu)){
					attempt++;
					continue;
				}

        		jeda_dan_hapus();
			
        		hasil_pintu = pintu1_2(pertama2, &attempt);
        		pertama2=0;
				if (!cek_benar(hasil_pintu)){
					attempt++;
					continue;
				}	

        		jeda_dan_hapus();

        		hasil_pintu = pintu1_3(pertama3, &attempt);
        		pertama3=0;
				if (!cek_benar(hasil_pintu)) {
					attempt++;
					continue;
				}
				
				jeda_dan_hapus();
				
        		pintu1ed();
        		
				jeda_dan_hapus();     	
        	
        		break;
        		}
        	
        	narasip2();
        	
			jeda_dan_hapus(); 
        	
        	//reset percobaan pertama
        	pertama1 = 1;
			pertama2 = 1;
			pertama3 = 1;
			
			//pintu 2 checkpoint
			while(1){
				hasil_pintu = pintu2_1(pertama1, &attempt);
				pertama1= 0;
				if (!cek_benar(hasil_pintu)) {
					attempt++;
					continue;
				}
				
				jeda_dan_hapus();
				
				hasil_pintu = pintu2_2(pertama1, &attempt);
				pertama2 = 0;
				if (!cek_benar(hasil_pintu)){
					attempt++;
					continue;
				}
				
				jeda_dan_hapus();
				
				hasil_pintu = pintu2_3(pertama1, &attempt);
				pertama3 = 0;
				if (!cek_benar(hasil_pintu)){
					attempt++;
					continue;
				}
						
				jeda_dan_hapus();		
								
				pintu2ed();
				
				jeda_dan_hapus();
				
				break;
			}
			
			narasip3();
			
			jeda_dan_hapus();
			
			pertama1 = 1;
			pertama2 = 1;
			pertama3 = 1;
			//pintu 3 checkpoint
			while (1){
				hasil_pintu = pintu3_1(pertama1, &attempt);
				pertama1= 0;
				if (!cek_benar(hasil_pintu)) {
					attempt++;
					continue;
				}
				
				jeda_dan_hapus();
			
				hasil_pintu = pintu3_2(pertama2, &attempt);
				pertama2 = 0;
				if (!cek_benar(hasil_pintu)){
					attempt++;
					continue;
				}
				
				jeda_dan_hapus();
				
				hasil_pintu = pintu3_3(pertama3, &attempt);
				pertama3 = 0;
				if (!cek_benar(hasil_pintu)){
					attempt++;
					continue;
				}
						
				jeda_dan_hapus();		
								
				pintu3ed();
				
				jeda_dan_hapus();
				
				narasiend(&attempt);
				save_leaderboard(nama, attempt);
				//selesai
				break;
			}
			jeda_dan_hapus();
        	break;
   		}	
		case 2:
    		system(CLEAR);
    		show_leaderboard();
    		jeda_dan_hapus();
    		break;
		case 3:
			system(CLEAR);
			printf ("Selamat tinggal...\n");
			printf ("Sampai jumpa di kesempatan berikutnya!\n");
			return 0;
		default:
			printf ("Input tidak valid!\n");
			jeda_dan_hapus();
			break;
		}
	}
	return 0;
}
