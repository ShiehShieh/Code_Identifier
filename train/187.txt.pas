program p1015;
const dx:array[1..4] of integer=(1,1,-1,-1);
      dy:array[1..4] of integer=(1,-1,1,-1);
var n,m,i,j,k,ans,x,y,ii,p,q:longint;
    map:array[0..300,0..300,1..2,1..4] of longint;
    vis,g:array[0..300,0..300] of boolean;
    s:string;
    line:array[1..40000,1..2] of longint;
Begin
    readln(n,m);
    for i:=1 to n do
    begin
        readln(s);
        for j:=1 to m do
        begin
        if (s[j]='\')or(s[j]='X') then begin g[i,j]:=true;g[i+1,j+1]:=true;map[i,j,1,1]:=1;map[i+1,j+1,1,4]:=1; end;
        if (s[j]='/')or(s[j]='X') then begin g[i,j+1]:=true;g[i+1,j]:=true;map[i,j+1,1,2]:=1;map[i+1,j,1,3]:=1; end;
        end;
    end;
    for i:=1 to n do
    begin
        readln(s);
        for j:=1 to m do
        begin
        if (s[j]='\')or(s[j]='X') then begin g[i,j]:=true;g[i+1,j+1]:=true;map[i,j,2,1]:=1;map[i+1,j+1,2,4]:=1; end;
        if (s[j]='/')or(s[j]='X') then begin g[i,j+1]:=true;g[i+1,j]:=true;map[i,j+1,2,2]:=1;map[i+1,j,2,3]:=1; end;
        end;
    end;
    inc(n);inc(m);
    for i:=1 to n do
    for j:=1 to m do
    if (vis[i,j]=false)and(g[i,j]) then
    begin
    k:=0;
    y:=1;x:=0;
    line[y,1]:=i;line[y,2]:=j;
    vis[i,j]:=true;
    while x<y do
    begin
    inc(x);
    p:=0;q:=0;
    for ii:=1 to 4 do
    begin
         p:=p+map[line[x,1],line[x,2],1,ii];
         q:=q+map[line[x,1],line[x,2],2,ii];
    end;
    k:=k+abs(p-q);
    for ii:=1 to 4 do
    if (vis[line[x,1]+dx[ii],line[x,2]+dy[ii]]=false)and(map[line[x,1],line[x,2],1,ii]+map[line[x,1],line[x,2],2,ii]>0) then
    begin
        vis[line[x,1]+dx[ii],line[x,2]+dy[ii]]:=true;
        inc(y);
        line[y,1]:=line[x,1]+dx[ii];
        line[y,2]:=line[x,2]+dy[ii];
    end;
    end;
    k:=k div 2;
    if k=0 then k:=1;
    ans:=ans+k;
    end;
    writeln(ans);
End.
