struct substring_data {
    string str1<100>;
    string str2<100>;
};

program SUBSTRING_PROG {
    version SUBSTRING_VERS {
        int CHECK_SUBSTRING(substring_data) = 1;
    } = 1;
} = 0x20000001;

