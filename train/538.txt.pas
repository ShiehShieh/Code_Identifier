var
s:string;
i,j,k:integer;
v,sh,b,q,sw,bw,qw:boolean;
begin
 readln(s);
 i:=1;
 if s[i]='-' then
begin
write('F');
inc(i);
end;
 if s[i]='.' then begin write('0'); v:=true; j:=i; end
 else begin
 while s[i]='0' do
inc(i);
 if s[i]='.' then dec(i);
 j:=i+1;
 while (s[j]<>'.') and (j<=length(s)) do
inc(j);
 k:=j-i;
 if j=length(s)+2 then write('0')
 else begin
 v:=false;
 sh:=false;
 b:=false;
 q:=false;
 sw:=false;
 bw:=false;
 qw:=false;
 while k>0 do
 begin
 case k of
1:if s[j-k]<>'0' then
begin
if (not sh) and (v) then
write('0');
write(s[j-k]);
v:=true;
 end;

2:if s[j-k]<>'0' then
begin
sh:=true;
if (not b) and (v) then
write('0');
write(s[j-k],'S');
v:=true;
end;

3:if s[j-k]<>'0' then
begin
b:=true;
if (not q) and (v) then
write('0');
write(s[j-k],'B');
v:=true;
end;
4:if s[j-k]<>'0' then
begin
q:=true;
write(s[j-k],'Q');
v:=true;
end;

5:begin
if s[j-k]<>'0' then
begin
if (not sw) and (v) then
write('0');
write(s[j-k]);
v:=true;
end;
if (qw) or (bw) or (sw) or (s[j-k]<>'0') then write('W');
end;

6:if s[j-k]<>'0' then
begin
sw:=true;
if (not bw) and (v) then
write('0');
write(s[j-k],'S');
v:=true;
end;

7:if s[j-k]<>'0' then
begin
bw:=true;
if (not qw) and (v) then
write('0');
write(s[j-k],'B');
v:=true;
end;

8:if s[j-k]<>'0' then
begin
qw:=true;
write(s[j-k],'Q');
v:=true;
end;
9:begin
write(s[j-k],'Y');
v:=true;
end;
end;
 dec(k);
 end;
 end;
 end;
 if j<length(s) then
 begin
 if not v then write('0');
 write('D');
 for k:=j+1 to length(s) do
 write(s[k]);
 end;
end.
