#include    <cstdio>
#include    <cstring>
#define     MAXN    56000
#define     MAXM    400000
#define     OO      1000000000
struct  arctype
{
        long    d , c , next ;
}   Arc[MAXM] ;
long    Vertex[MAXN] , Hold[MAXN]={0} , Dis[MAXN]={0} ,
        Pre[MAXN] , Cur[MAXN] , Save[MAXN] , 
        Flow = 0 , Tot = -1 , Ans = 0 ,
        N , M , S , T ;

inline  void    addarc( long u , long v , long w )
{
        Arc[++Tot].d = v ;  Arc[Tot].c = w ;
        Arc[Tot].next = Vertex[u] ;  Vertex[u] = Tot ;
}

void    enter( void )
{
        long    i , u , v , w ;
        memset( Vertex , -1 , sizeof( Vertex ) ) ;
        scanf( "%ld%ld" , &N , &M ) ;
        S = N+M+1 ;  T = N+M+2 ;
        for  ( u = 1 ; u <= N ; u++ )
        {
            scanf( "%ld" , &w ) ;
            addarc( u , T , w ) ;
            addarc( T , u , 0 ) ;
        }
        for  ( i = 1 ; i <= M ; i++ )
        {
            scanf( "%ld%ld%ld" , &u , &v , &w ) ;
            Ans += w ;
            addarc( S , N+i , w ) ;
            addarc( N+i , S , 0 ) ;
            addarc( N+i , u , OO ) ;
            addarc( u , N+i , 0 ) ;
            addarc( N+i , v , OO ) ;
            addarc( v , N+i , 0 ) ;
        }
        N += M+2 ;
}
            
void    solve( void )
{
        long    u , p , min , k , aug ;
        bool    found ;
        u = S ;
        aug = 0x7f ;
        while  ( Dis[S] < N )
        {
            Save[u] = aug ;
            found = 0 ;
            p = Cur[u] ;
            while  ( p != -1 )
            {
                if  ( Arc[p].c && Dis[u] == Dis[Arc[p].d]+1 )
                {
                    found = 1 ;
                    Cur[u] = p ;
                    if  ( Arc[p].c < aug )
                        aug = Arc[p].c ;
                    Pre[Arc[p].d] = p ;
                    u = Arc[p].d ;
                    if  ( u == N )
                    {
                        Flow += aug ;
                        while  ( u != S )
                        {
                            Arc[Pre[u]].c -= aug ;
                            Arc[Pre[u]^1].c += aug ;
                            u = Arc[Pre[u]^1].d ;
                        }
                        aug = 0x7f ;
                    }
                    break ;
                }
                p = Arc[p].next ;
            }
            if  ( found )
                continue ;
            min = N-1 ;
            p = Vertex[u] ;
            while  ( p != -1 )
            {
                if  ( Arc[p].c && Dis[Arc[p].d] < min )
                {
                    k = p ;
                    min = Dis[Arc[p].d] ;
                }
                p = Arc[p].next ;
            }
            Cur[u] = k ;
            Hold[Dis[u]]-- ;
            if  ( ! Hold[Dis[u]] )
                break ;
            Dis[u] = min+1 ;
            Hold[Dis[u]]++ ;
            if  ( u != S )
            {
                u = Arc[Pre[u]^1].d ;
                aug = Save[u] ;
            }
        }
        printf( "%ld\n" , Ans-Flow ) ;
}

int     main()
{

        
        enter() ;
        solve() ;
        
        return  0 ;
}

