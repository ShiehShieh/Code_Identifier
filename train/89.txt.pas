program voj1518;
var f:array[0..100,0..100,-1..100] of longint;
    w,d,d2,son,nx:array[-1..100] of longint;
    i,j,p,n,k,v,tmp:longint;
function min(a,b:longint):longint;
begin
    if a<b then exit(a) else exit(b);
end;
procedure dfs(dep,n:longint);
begin
    d2[dep]:=d2[dep-1]+d[n];
    if son[n]=0 then
        for i:=0 to dep-1 do begin
            f[n,i,0]:=(d2[dep]-d2[i])*w[n];
            f[n,i,1]:=0;
        end
    else begin
        dfs(dep+1,son[n]);
        for p:=0 to dep-1 do
            for i:=0 to k do
                f[n,p,i]:=min(f[son[n],p,i]+(d2[dep]-d2[p])*w[n],f[son[n],dep,i-1]);
    end;
    if nx[n]<>0 then begin
        dfs(dep,nx[n]);
        for p:=0 to dep-1 do
            for i:=k downto 0 do begin
                tmp:=maxlongint;
                for j:=0 to i do
                    if f[n,p,j]+f[nx[n],p,i-j]<tmp then tmp:=f[n,p,j]+f[nx[n],p,i-j];
                f[n,p,i]:=tmp;
            end;
    end;
end;
begin
    readln(n,k);
    for n:=1 to n do begin
        readln(w[n],v,d[n]);
        nx[n]:=son[v]; son[v]:=n;
    end;
    fillchar(f,sizeof(f),$3F); dfs(0,0); writeln(f[son[0],0,k]);
end.
