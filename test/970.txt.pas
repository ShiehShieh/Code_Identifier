const
 xx1:array[1..7]of integer=(-1,-1,-1,-1, 0, 0, 0);
 xx2:array[1..7]of integer=(-1,-1, 0, 0,-1,-1, 0);
 xx3:array[1..7]of integer=(-1, 0,-1, 0,-1, 0,-1);
var
 n,i,j:longint;
 f:array[-10..50,-10..50,-10..50,-10..50] of longint;
 g:array[-10..50,-10..50] of longint;
procedure dp;
var
   x1,x2,x3:longint;
begin
   for i:=1 to n*2-1 do
    for x1:=1 to n do
      for x2:=1 to n do
        for x3:=1 to n do
          begin
            f[i,x1,x2,x3]:=f[i-1,x1,x2,x3];
              for j:=1 to 7 do
                if f[i-1,x1+xx1[j],x2+xx2[j],x3+xx3[j]]>f[i,x1,x2,x3]
                  then f[i,x1,x2,x3]:=f[i-1,x1+xx1[j],x2+xx2[j],x3+xx3[j]];
                    if x1<>x2
                     then inc(f[i,x1,x2,x3],(g[x1,i+1-x1]+g[x2,i+1-x2]))
                      else inc(f[i,x1,x2,x3],g[x1,i+1-x1]);
                       if (x3<>x1)and(x3<>x2)
                        then inc(f[i,x1,x2,x3],g[x3,i+1-x3]);
              end;
 end;
begin
 readln(n);
 fillchar(f,sizeof(f),0);
 fillchar(g,sizeof(g),0);
 for i:=1 to n do
   for j:=1 to n do
     read(g[i,j]);
 dp;
 writeln(f[n*2-1,n,n,n]);
end.

