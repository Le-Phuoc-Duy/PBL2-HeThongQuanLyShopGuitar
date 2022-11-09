if (x[i] < 48 || x[i] > 57) throw "";
                else this->thang += (int)(x[i] - '0') * count_pow;
                count_pow *= 10;
            }