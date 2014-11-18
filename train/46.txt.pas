const
  MAXN=60010;
  MAXM=500000;
var
  n,m,i,s,t,x,y,z,es,dinic,ans:longint;
  u,c,next,rev,num:array[1..MAXM] of longint;
  link,height,list,link0:array[1..MAXN] of longint;
procedure make_edge(x,y,z:longint);
  begin
    inc(es);
    u[es]:=z;
    num[es]:=y;
    rev[es]:=es+1;
    next[es]:=link[x];
    link[x]:=es;
    inc(es);
    u[es]:=0;
    num[es]:=x;
    rev[es]:=es-1;
    next[es]:=link[y];
    link[y]:=es;
  end;
procedure init;
  begin
    readln(n,m);
    s:=n+m+1;
    t:=n+m+2;
    es:=0;
    ans:=0;
    for i:=1 to n do
      begin
        read(x);
        make_edge(s,i,x);
      end;
    for i:=1 to m do
      begin
        readln(x,y,z);
        make_edge(x,i+n,maxlongint);
        make_edge(y,i+n,maxlongint);
        make_edge(i+n,t,z);
        inc(ans,z);
      end;
    n:=n+m+2;
    link0:=link;
  end;
procedure bfs;
  var head,tail,nownode,nowedge:longint;
  begin
    for i:=1 to n do height[i]:=maxlongint;
    list[1]:=t;
    height[t]:=0;
    head:=1;
    tail:=1;
    while head>=tail do
      begin
        nownode:=list[tail];
        inc(tail);
        nowedge:=link[nownode];
        while nowedge>0 do
          begin
            if (height[num[nowedge]]>n shl 1)and(u[rev[nowedge]]>0) then
              begin
                height[num[nowedge]]:=height[nownode]+1;
                inc(head);
                list[head]:=num[nowedge];
              end;
            nowedge:=next[nowedge];
          end;
      end;
  end;
function dfs(now,low:longint):longint;
  var nowedge,tmp:longint;
  begin
    if now=t then exit(low);
    dfs:=0;
    nowedge:=link[now];
    while (low>0)and(nowedge>0) do
      begin
        if (height[num[nowedge]]=height[now]-1)and
          (u[nowedge]>0)and(link[num[nowedge]]>0) then
          begin
            if u[nowedge]<low then tmp:=dfs(num[nowedge],u[nowedge])
                              else tmp:=dfs(num[nowedge],low);
            dec(low,tmp);
            dec(u[nowedge],tmp);
            inc(dfs,tmp);
            inc(u[rev[nowedge]],tmp);
          end;
        if low>0 then nowedge:=next[nowedge];
      end;
 //   link[now]:=nowedge;
  end;
begin
  init;
  dinic:=0;
  fillchar(list,sizeof(list),0);
  bfs;
  repeat
    link:=link0;
    inc(dinic,dfs(s,maxlongint));
    bfs;
    until height[s]>n shl 1;
  writeln(ans-dinic);
end.
