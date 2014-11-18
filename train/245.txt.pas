const
        maxn=5008;
var
f:array[0..maxn,0..3] of longint;
s:ansistring;
i,j,n,l,r,k1,k2,k0:longint;
function min(a,b:longint):longint;
begin
        if(a<b)then exit(a)
        else exit(b);
end;
begin
        readln(n);
        readln(s);
        //fillchar(f,sizeof(f),0);
        k0:=2;
        k1:=1;
        k2:=0;
        for i:=2 to n do
        begin
                for j:=1 to n-i+1 do
                begin
                l:=j;
                r:=i+j-1;
                //if(r>n)then break;
                if(s[l]=s[r])then
                f[j,{(i+30)mod 3}k0]:=f[j+1,{(i-2+30)mod 3}k2]
                else
                f[j,{i mod 3}k0]:=maxlongint div 100;

                f[j,{i mod 3}k0]:=min(f[j,{i mod 3}k0],f[j+1,{(i-1+30)mod 3}k1]+1);
                f[j,{i mod 3}k0]:=min(f[j,{i mod 3}k0],f[j,{(i-1+30)mod 3}k1]+1);
                end;
                if(i<>n)then
                begin
                j:=k0;
                k0:=k2;
                k2:=k1;
                k1:=j;
                end;
        end;
        writeln(f[1,k0]);
end.                                           
