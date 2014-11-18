program hhhhh;
const
        move:array[1..6,1..3] of integer=
          ((0,0,1),(0,0,-1),
           (0,1,0),(0,-1,0),
           (1,0,0),(-1,0,0));
var
        a,b:array[0..100,0..100,0..100] of int64;
        i,j,k,l,o,n,m:longint;
procedure init;
begin
        readln(o,n,m);
end;

procedure work;
begin
        a[1,1,m]:=1;
        for o:=1 to o do begin
          for i:=1 to n do
            for j:=1 to n do
              for k:=1 to n do
                if ord((i=1) or (i=n))+
                   ord((j=1) or (j=n))+
                   ord((k=1) or (k=n))>=2 then
                for l:=1 to 6 do
                  inc(b[i+move[l][1],j+move[l][2],k+move[l][3]],a[i][j][k]);
          a:=b;
          fillchar(b,sizeof(b),0);
          end;
end;

procedure print;
begin
        writeln(a[1,1,m]);
end;

begin
        init;
        work;
        print;
end.
