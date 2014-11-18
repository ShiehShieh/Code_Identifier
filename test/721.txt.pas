program p1082;
const mn=5000;
      max=1E20;
type link=^pt;
     pt=record po:integer;c,d:real;
                next:link;end;
var n,m,k,s,t:longint;
    h:array[1..mn] of pt;
    dis,tl:array[1..mn] of real;
procedure readdata;
var i,j,x,y,u:longint;
     q,p:link;
     ok:boolean;
     l,lc:real;
begin

     fillchar(h,sizeof(h),0);
     readln(n,m);
     for i:=1 to n do h[i].next:=nil;
     for i:=1 to m do
     begin
          new(q);
          read(x,q^.po,q^.c,q^.d);
          q^.next:=h[x].next;
          h[x].next:=q;
          y:=q^.po;
          new(p);
          p^.next:=h[y].next;
          h[y].next:=p;
          p^.po:=x;p^.d:=q^.d;p^.c:=q^.c
     end;
     readln(s,t);
     readln(k);
     for i:=1 to n do
     begin dis[i]:=max;tl[i]:=max end;
     dis[s]:=0;tl[s]:=0;
     repeat
        ok:=false;
        for u:=1 to n do
        if (dis[u]<max) and (tl[u]<=k) then
        begin
             q:=h[u].next;
             while q<>nil do
             begin
                j:=q^.po;l:=dis[u]+q^.d;lc:=tl[u]+q^.c;
                if (l<dis[j]) and (lc<=k)
                then begin dis[j]:=l;tl[j]:=lc;ok:=true end;
                q:=q^.next;
             end;
        end;
     until not ok;
     if dis[t]<max then writeln(dis[t]:0:0)
     else begin
               writeln(-1);
          end;
end;
begin
    readdata;
end.

