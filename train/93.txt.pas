const
        maxn=1007;
        maxlen=8000;
var
a,b:array[0..maxn] of longint;
f:array[0..maxn,-maxlen..maxlen] of longint;
min,max,i,j,m,n,more,all,ans:longint;
function getmin(a,b:longint):longint;
begin
        if(a<b)then exit(a)
        else exit(b);
end;
begin
        read(n);
        min:=0;
        max:=0;
        for i:=1 to n do
        begin
        read(a[i],b[i]);
        if(a[i]<b[i])then
        begin
                min:=min+a[i];
                max:=max+b[i];
        end
        else
        begin
                min:=min+b[i];
                max:=max+a[i];
        end;
        end;
        all:=abs(max-min);
        f[1,a[1]-b[1]]:=1;
        f[1,b[1]-a[1]]:=2;
        for i:=2 to n do
        begin
                for j:=-all to all do
                begin
                f[i,j]:=maxlongint div 100;
                more:=a[i]-b[i];
                if(f[i-1,j-more]<>0)then
                begin
                f[i,j]:=getmin(f[i,j],f[i-1,j-more]);
                end;
                if(f[i-1,j+more]<>0)then
                begin
                f[i,j]:=getmin(f[i,j],f[i-1,j+more]+1);
                end;
                end;
        end;
        ans:=maxlongint div 100;
        for i:=0 to all do
        begin
                if(f[n,i]<>0)then
                begin
                        ans:=getmin(ans,f[n,i]);
                end;
                if(f[n,-i]<>0)then
                begin
                        ans:=getmin(ans,f[n,-i]);
                end;
                if(ans<>maxlongint div 100)then break;
        end;
        writeln(ans-1);
end.
                                            
