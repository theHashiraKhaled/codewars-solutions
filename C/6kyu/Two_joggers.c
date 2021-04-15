typedef struct Laps_Pairing {
    int bob;
    int charles;
} laps;

laps nbr_of_laps(int x, int y) 
{
    int l = x;
    while (l % y != 0) l += x;
    laps output = {l/x, l/y};
    return output;
}
