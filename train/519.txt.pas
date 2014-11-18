program sbt;
var
key,l,r,s:array[0..100000] of longint;
i,j,k,n,m,t,delta,min,temp,now,total:longint;
p:char;

procedure right(var t:longint);
var k:longint;
begin
k:=l[t];
l[t]:=r[k];
r[k]:=t;
s[k]:=s[t];
s[t]:=s[l[t]]+s[r[t]]+1;
t:=k;
end;

procedure left(var t:longint);
var k:longint;
begin
k:=r[t];
r[t]:=l[k];
l[k]:=t;
s[k]:=s[t];
s[t]:=s[l[t]]+s[r[t]]+1;
t:=k;
end;

procedure maintain(var t:longint;flag:boolean);
var k:longint;
begin
if flag then
     if s[l[l[t]]]>s[r[t]] then
          right(t)
     else if s[r[l[t]]]>s[r[t]] then
          begin
          left(l[t]);
          right(t);
          end
     else exit
else if s[r[r[t]]]>s[l[t]] then
          left(t)
     else if s[l[r[t]]]>s[l[t]] then
          begin
          right(r[t]);
          left(t);
          end
     else exit;
maintain(l[t],false); maintain(r[t],true);
maintain(t,true); maintain(t,false);
end;

procedure insert(var t:longint;v:longint);
begin
if t=0 then
     begin
     inc(total);
     t:=total;
     key[t]:=v;
     l[t]:=0; r[t]:=0; s[t]:=1;
     exit;
     end;
inc(s[t]);
if v<key[t] then
     insert(l[t],v)
else insert(r[t],v);
maintain(t,v<key[t]);
end;

function delete(var t:longint;v:longint):longint;
begin
dec(s[t]);
if (v=key[t])or(v<key[t])and(l[t]=0)or(v>key[t])and(r[t]=0) then
     begin
     delete:=key[t];
     if (l[t]=0)or(r[t]=0) then
          t:=l[t]+r[t]
     else key[t]:=delete(l[t],key[t]+1);
     exit;
     end;
if v<key[t] then
     delete:=delete(l[t],v)
else delete:=delete(r[t],v);
end;

function select(t,k:longint):longint;
begin
if s[l[t]]+1=k then
     exit(key[t]);
if k<=s[l[t]] then
     select:=select(l[t],k)
else select:=select(r[t],k-s[l[t]]-1);
end;

procedure work;
begin
readln(n,min);
for i:=1 to n do
     begin
     readln(p,k);
     case p of
          'I': if k>=min then
                    begin
                    inc(now);
                    insert(t,k-delta);
                    end;
          'A': delta:=delta+k;
          'S': begin
               delta:=delta-k;
               while now>0 do
                    begin
                    temp:=select(t,1);
                    if temp+delta>=min then break;
                    dec(now); delete(t,temp);
                    end;
               end;
          'F': if k>now then write(-1) else write(select(t,now-k+1)+delta);
          end;
     end;
writeln(total-now);
end;

begin
work;
end.
