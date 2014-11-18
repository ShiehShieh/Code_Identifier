program p1480;
var
num:array[1..4] of longint;
i,j,k,n:longint;
sum:longint;
str:ansistring;
f:array[0..65540] of integer;
b:array[1..65540,0..5] of longint;
procedure init;
var
j,j1,i,l:longint;
begin
        sum:=0;
        fillword(f,sizeof(f) shr 1,10);
        readln(str);
        l:=length(str);
        if trunc(sqrt(l))=sqrt(l) then
        begin
                n:=1;
                num[1]:=trunc(sqrt(l));
                exit;
        end;
        for i:=1 to l do
        begin
                b[i,0]:=2;
                b[i,1]:=i;
        end;
        for i:=1 to trunc(sqrt(l)) do
        f[i*i]:=1;
        for i:=2 to l do
        if trunc(sqrt(i))<>sqrt(i) then
        begin
                for j:=trunc(sqrt(i)) downto 1 do
                if f[i]>f[i-j*j]+1 then
                begin
                        f[i]:=f[i-j*j]+1;
                        j1:=i-j*j;
                end;
                for n:=2 to b[j1,0] do
                begin
                        b[i,n]:=b[j1,n-1];
                        inc(b[i,0]);
                end;
        end;
        n:=f[l];
        j1:=0;
        for i:=n downto 1 do
        begin
                num[i]:=trunc(sqrt(b[l,i]-j1));
                j1:=b[l,i];
        end;
end;
begin
        init;
        for i:=1 to n do
        begin
                for j:=1 to num[i] do
                for k:=1 to num[i] do
                write(str[sum+j+num[i]*(k-1)]);
                sum:=sum+num[i]*num[i];
        end;
end.

