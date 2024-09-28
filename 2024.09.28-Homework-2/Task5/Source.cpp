#include <iostream>
#include <cstdio>

int main(int argc, char* argv[]) 
{
    int l1, w1, h1, l2, w2, h2, lc, wc, hc, l;
    bool cont = true;
    
    scanf_s("%d %d %d %d %d %d %d %d %d", &l1, &w1, &h1, &l2, &w2, &h2, &lc, &wc, &hc);
    l = l1;
    l1 = std::max(l1, w1);
    w1 = std::min(l, w1);
    l = l2;
    l2 = std::max(l2, w2);
    w2 = std::min(l, w2);
    l = lc;
    lc = std::max(lc, wc);
    wc = std::min(l, wc);
    if (l1 <= lc && w1 <= wc && l2 <= lc && w2 <= wc) 
    {
        if (h1 > hc || h2 > hc) 
        {
            printf("NO");
            cont = false;
        }
        if (cont && l1 <= lc && w1 <= wc) 
        {
            if (cont && l2 <= wc - w1 && w2 <= lc) 
            {
                printf("YES");
                cont = false;
            }
            else if (cont && w2 <= wc - w1 && l2 <= lc) 
            {
                printf("YES");
                cont = false;
            }
            else if (cont && l2 <= lc - l1 && w2 <= wc) 
            {
                printf("YES");
                cont = false;
            }
            else if (cont && w2 <= lc - l1 && l2 <= wc)
            {
                printf("YES");
                cont = false;
            }
        }
        if (cont && w1 <= lc && l1 <= wc) 
        {
            if (cont && l2 <= wc - l1 && w2 <= lc) 
            {
                printf("YES");
                cont = false;
            }
            else if (cont && l2 <= lc && w2 <= wc - l1) 
            {
                printf("YES");
                cont = false;
            }
            else if (cont && l2 <= lc - w1 && w2 <= wc) 
            {
                printf("YES");
                cont = false;
            }
            else if (cont && w2 <= lc - w1 && l2 <= wc) 
            {
                printf("YES");
                cont = false;
            }
        }
        if (cont && h1 + h2 <= hc && l1 <= lc && w1 <= wc && l2 <= lc && w2 <= wc) 
        {
            printf("YES");
            cont = false;
        }
        else if (cont) 
        {
            printf("NO");
        }
    }
    else 
    {
        printf("NO");
    }
    return EXIT_SUCCESS;
}
