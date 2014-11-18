var
        n,m,i,min,o:longint;
        f:array[0..51] of boolean;
        a:array[1..50,1..2] of longint;
function pan:boolean;
var
        j:longint;
begin
        for j:=1 to n do if f[j] then exit(false);
        pan:=true;
end;
procedure dfs(i,l:longint);
var
        j,x,k:longint;
begin
        if l>=min then exit;
        if pan then begin
                min:=l;
                exit;
        end;
        j:=i;
        while not(f[j]) do inc(j);
        if (j<=n) then begin
                x:=0;
                for k:=1 to n do if f[k] then x:=x+(a[j,1]-a[i,1])*a[k,2];
                f[j]:=false;
                dfs(j,l+x);
                f[j]:=true;
        end;
        j:=i;
        while not(f[j]) do dec(j);
        if (j>0) then begin
                x:=0;
                for k:=1 to n do if f[k] then x:=x+(a[i,1]-a[j,1])*a[k,2];
                f[j]:=false;
                dfs(j,l+x);
                f[j]:=true;
        end;
end;
begin
        read(n);
        if n=0 then begin
                writeln(0);
                exit;
        end;
        read(m);
        for i:=1 to n do read(a[i,1],a[i,2]);
        fillchar(f,sizeof(f),true);
        f[m]:=false;
        min:=maxlongint;
        dfs(m,0);
        writeln(min);
end.
