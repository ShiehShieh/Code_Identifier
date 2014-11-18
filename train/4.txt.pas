program voj1325;
var e,nx:array[2..20001] of longint;
    h,d,a,fa,deg:array[1..5000] of longint;
    i,j,k,n,m,ans:longint;
procedure dfs(f,i:longint);
begin
    a[i]:=d[i];
    while h[i]<>0 do begin
        j:=e[h[i]];
        if d[j]=0 then begin
            d[j]:=d[i]+1; dfs(h[i] xor 1,j); j:=e[h[i]];
            if a[j]<a[i] then a[i]:=a[j];
            if a[j]>d[i] then begin inc(ans); inc(deg[i]); inc(deg[j]); end
            else fa[j]:=i;
        end
        else if (f<>h[i]) and (d[j]<a[i]) then a[i]:=d[j];
        h[i]:=nx[h[i]];
    end;
end;
function father(n:longint):longint;
begin
    if fa[n]=0 then exit(n);
    if fa[fa[n]]=0 then exit(fa[n]);
    father:=father(fa[fa[n]]);
    fa[n]:=father;
end;
begin
    readln(n,m);
    for m:=1 to m do begin
        readln(i,j);
        e[m<<1]:=j; nx[m<<1]:=h[i]; h[i]:=m<<1;
        e[m<<1+1]:=i; nx[m<<1+1]:=h[j]; h[j]:=m<<1+1;
    end;
    d[1]:=1; dfs(0,1); writeln(ans); ans:=0;
    for n:=1 to n do if father(n)<>n then inc(deg[fa[n]],deg[n]);
    for n:=1 to n do if (fa[n]=0) and (deg[n]=1) then inc(ans);
    writeln((ans+1)>>1);
end.
