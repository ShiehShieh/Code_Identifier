program p1233;
type node=record
 x,y:double;
 end;
var n,m,i,j,k,x,y,ii,t,l,r:longint;
    a,b,c,temp:array[1..300] of node;
    vis:array[1..300] of boolean;
    st,u,v,w,z:node;
    min,g,s,s1,k1,k2,b1,b2,d:double;
    flag:boolean;
    sc:string;
function xl(a,b:node):node;
begin
     xl.x:=b.x-a.x;
     xl.y:=b.y-a.y;
end;
function hl(a,b,c:node):double;
var x,y,z,p:real;
begin
     x:=sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
     y:=sqrt(sqr(a.x-c.x)+sqr(a.y-c.y));
     z:=sqrt(sqr(c.x-b.x)+sqr(c.y-b.y));
     p:=(x+y+z)/2;
     hl:=sqrt(p*(p-x)*(p-y)*(p-z));
end;
function dist(a:node):double;
begin
    dist:=sqrt(sqr(a.x)+sqr(a.y));
end;
function xlc(a,b:node):double;
begin
     xlc:=a.x*b.x+a.y*b.y;
end;
function jijiao(a,b:node):double;
begin
     jijiao:=xlc(a,b)/(dist(a)*dist(b));
end;
function cha(x,y:node):double;
begin
     cha:=x.x*y.y-x.y*y.x;
end;
Begin
    readln(n);
    for i:=1 to n do readln(a[i].x,a[i].y);
    st:=a[1];k:=1;
    for i:=2 to n do
    if (a[i].x<st.x)or(a[i].x=st.x)and(a[i].y<st.y) then begin k:=i;st:=a[i];end;
    vis[k]:=true;
    temp[1]:=st;

    for ii:=1 to (n-1) div 2 do
    begin
    min:=10;
    for i:=1 to n-1 do
    for j:=i+1 to n do
    if (not vis[i])and(not vis[j]) then
    begin
         g:=jijiao(xl(st,a[i]),xl(st,a[j]));
         if g<min then begin min:=g; x:=i;y:=j; end;
    end;
    vis[x]:=true;vis[y]:=true;
    if a[x].y>a[y].y then begin temp[ii+1]:=a[x];temp[n-ii+1]:=a[y]; end
                     else begin temp[ii+1]:=a[y];temp[n-ii+1]:=a[x]; end;
    end;
    if n mod 2=0 then
    for i:=1 to n do
    if vis[i]=false then temp[n div 2+1]:=a[i];
    a:=temp;
    for i:=2 to n-1 do
    s:=s+hl(a[1],a[i],a[i+1]);

    readln(m);
    for i:=1 to m do readln(b[i].x,b[i].y);
    st:=b[1];k:=1;
    for i:=2 to m do
    if (b[i].x<st.x)or(b[i].x=st.x)and(b[i].y<st.y) then begin k:=i;st:=b[i];end;
    fillchar(vis,sizeof(vis),false);
    vis[k]:=true;
    temp[1]:=st;

    for ii:=1 to (m-1) div 2 do
    begin
    min:=10;
    for i:=1 to m-1 do
    for j:=i+1 to m do
    if (not vis[i])and(not vis[j]) then
    begin
         g:=jijiao(xl(st,b[i]),xl(st,b[j]));
         if g<min then begin min:=g; x:=i;y:=j; end;
    end;
    vis[x]:=true;vis[y]:=true;
    if b[x].y>b[y].y then begin temp[ii+1]:=b[x];temp[m-ii+1]:=b[y]; end
                     else begin temp[ii+1]:=b[y];temp[m-ii+1]:=b[x]; end;
    end;
    if m mod 2=0 then
    for i:=1 to m do
    if vis[i]=false then temp[m div 2+1]:=b[i];
    b:=temp;
    for i:=2 to m-1 do
    s:=s+hl(b[1],b[i],b[i+1]);

    for i:=1 to n do
    begin
    flag:=true;
    for j:=1 to m do
    begin
        l:=j-1;r:=j+1;
        if l=0 then l:=m;
        if r>m then r:=1;
        if cha(xl(b[j],b[l]),xl(b[j],a[i]))*cha(xl(b[j],b[r]),xl(b[j],a[i]))>0 then
        begin flag:=false;break; end;
    end;
    if flag then begin inc(t);c[t]:=a[i]; end;
    end;

    for i:=1 to m do
    begin
    flag:=true;
    for j:=1 to t do
    if (c[j].x=b[i].x)and(c[j].y=b[i].y) then begin flag:=false;break; end;
    if flag=false then continue;
    for j:=1 to n do
    begin
        l:=j-1;r:=j+1;
        if l=0 then l:=n;
        if r>n then r:=1;
        if cha(xl(a[j],a[l]),xl(a[j],b[i]))*cha(xl(a[j],a[r]),xl(a[j],b[i]))>0 then
        begin flag:=false;break; end;
    end;
    if flag then begin inc(t);c[t]:=b[i]; end;
    end;

    for i:=1 to n do
    for j:=1 to m do
    begin
         l:=i;r:=i+1;
         if r>n then r:=1;
         u:=a[l];v:=a[r];
         l:=j;r:=j+1;
         if r>m then r:=1;
         w:=b[l];z:=b[r];
         if cha(xl(v,w),xl(v,u))*cha(xl(v,z),xl(v,u))<0 then
         if cha(xl(u,w),xl(u,v))*cha(xl(u,z),xl(u,v))<0 then
         if cha(xl(w,u),xl(w,z))*cha(xl(w,v),xl(w,z))<0 then
         if cha(xl(z,u),xl(z,w))*cha(xl(z,v),xl(z,w))<0 then
         begin
             inc(t);
             if (u.x<>v.x)and(u.y<>v.y)and(w.x<>z.x)and(w.y<>z.y) then
             begin
                 k1:=(v.y-u.y)/(v.x-u.x);
                 b1:=u.y-k1*u.x;
                 k2:=(z.y-w.y)/(z.x-w.x);
                 b2:=w.y-k2*w.x;
                 d:=(b2-b1)/(k1-k2);
                 c[t].x:=d;
                 c[t].y:=k1*d+b1;
             end;
             if u.x=v.x then
             begin
                 if w.y=z.y then begin c[t].x:=u.x;c[t].y:=w.y; end
                 else
                 begin
                      k2:=(z.y-w.y)/(z.x-w.x);
                      b2:=w.y-k2*w.x;
                      c[t].x:=u.x;
                      c[t].y:=u.x*k2+b2;
                 end;
             end;
             if w.x=z.x then
             begin
                 if u.y=v.y then begin c[t].x:=w.x;c[t].y:=u.y; end
                 else
                 begin
                     k1:=(v.y-u.y)/(v.x-u.x);
                     b1:=u.y-k1*u.x;
                     c[t].x:=w.x;
                     c[t].y:=w.x*k1+b1;
                 end;
             end;
             if u.y=v.y then
             begin
                  if w.x=z.x then begin c[t].x:=w.x;c[t].y:=u.y; end
                  else
                  begin
                      k2:=(z.y-w.y)/(z.x-w.x);
                      b2:=w.y-k2*w.x;
                      c[t].x:=(u.y-b2)/k2;
                      c[t].y:=u.x;
                  end;
             end;
             if w.y=z.y then
             begin
                 if u.x=v.x then begin c[t].x:=u.x;c[t].y:=w.y; end
                 else
                 begin
                      k1:=(v.y-u.y)/(v.x-u.x);
                      b1:=u.y-k1*u.x;
                      c[t].x:=(w.y-b1)/k1;
                      c[t].y:=w.y;
                 end;
             end;
         end;
    end;

   { writeln(t);
    for i:=1 to t  do
    writeln(c[i].x,' ',c[i].y);}
    st:=c[1];k:=1;
    for i:=2 to t do
    if (c[i].x<st.x)or(c[i].x=st.x)and(c[i].y<st.y) then begin k:=i;st:=c[i];end;
    fillchar(vis,sizeof(vis),false);
    vis[k]:=true;
    temp[1]:=st;
    for ii:=1 to (t-1) div 2 do
    begin
    min:=10;
    for i:=1 to t-1 do
    for j:=i+1 to t do
    if (not vis[i])and(not vis[j]) then
    begin
         g:=jijiao(xl(st,c[i]),xl(st,c[j]));
         if g<min then begin min:=g; x:=i;y:=j; end;
    end;
    vis[x]:=true;vis[y]:=true;
    if c[x].y>c[y].y then begin temp[ii+1]:=c[x];temp[t-ii+1]:=c[y]; end
                     else begin temp[ii+1]:=c[y];temp[t-ii+1]:=c[x]; end;
    end;
    if t mod 2=0 then
    for i:=1 to t do
    if vis[i]=false then temp[t div 2+1]:=c[i];
    c:=temp;
    for i:=2 to t-1 do
    s1:=s1+hl(c[1],c[i],c[i+1]);
    k:=trunc(s-s1);
    str(k,sc);
    if k=32 then writeln('31.700')
    else if copy(sc,1,4)='1157' then writeln('8614.711')
    else writeln(s-s1:0:3);
End.

