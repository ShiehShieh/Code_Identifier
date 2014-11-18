program vijos_p1081;
const
  maxn=200000;
  maxm=50000;
var
  a:array[0..maxn]of longint;
  n,m,root,k,num,p1,p2:longint;
  key,right,left,rank,size:array[0..maxn]of longint;
  head,tail,ans,queue:array[1..maxm]of longint;
procedure right_rotate(var t:longint);
  begin
    k:=left[t];
    left[t]:=right[k];
    right[k]:=t;
    size[k]:=size[t];
    size[t]:=size[left[t]]+size[right[t]]+1;
    t:=k;
  end;
procedure left_rotate(var t:longint);
  begin
    k:=right[t];
    right[t]:=left[k];
    left[k]:=t;
    size[k]:=size[t];
    size[t]:=size[right[t]]+size[left[t]]+1;
    t:=k;
  end;
procedure maintain(var t:longint;  flag:boolean);
  begin
    if not flag then
      begin
        if (size[left[left[t]]]>size[right[t]]) then
          right_rotate(t)
        else if (size[right[left[t]]]>size[right[t]]) then
          begin
            left_rotate(left[t]);
            right_rotate(t);
          end
        else exit
      end
    else
      begin
        if (size[right[right[t]]]>size[left[t]]) then
          left_rotate(t)
        else if (size[left[right[t]]]>size[left[t]]) then
          begin
            right_rotate(right[t]);
            left_rotate(t);
          end
        else exit;
      end;
    maintain(left[t],false);
    maintain(right[t],true);
    maintain(t,true);
    maintain(t,false);
  end;

function delete(var t:longint; v:longint):longint;
  begin
   dec(size[t]);
   if (key[t]=v)
       or ((key[t]>v) and (left[t]=0))
       or ((key[t]<v) and (right[t]=0)) then
     begin
       delete:=key[t];
       if (left[t]=0)or(right[t]=0) then
         t:=left[t]+right[t]                      //--?
       else key[t]:=delete(left[t],key[t]+1);
     end
   else
     begin
       if v<key[t] then delete:=delete(left[t],v )
         else           delete:=delete(right[t],v);
     end;
  end;

function select(t:longint; v:longint):longint;
  begin
    if (size[left[t]]+1)=v then exit(key[t]);
    if size[left[t]]>=v then exit(select(left[t],v));
    exit(select(right[t],v-size[left[t]]-1));
  end;

procedure insert(var t:longint; x:longint);
  begin
    if t=0 then
      begin
        inc(num);
        t:=num;
        key[t]:=x;
        size[t]:=1;
        exit;
      end;
    inc(size[t]);
    if x<key[t] then insert(left[t],x)
      else insert(right[t],x);
    maintain(t,x>=key[t]);
  end;

procedure qsort(l,r:longint);
  var
    i,j,mid,temp:longint;
  begin
    i:=l; j:=r; mid:=head[(l+r)shr 1];
    repeat
      while head[i]<mid do inc(i);
      while head[j]>mid do dec(j);
      if i<=j then
        begin
          temp:=head[i]; head[i]:=head[j]; head[j]:=temp;
          temp:=tail[i]; tail[i]:=tail[j]; tail[j]:=temp;
          temp:=rank[i]; rank[i]:=rank[j]; rank[j]:=temp;
          temp:=queue[i];queue[i]:=queue[j];queue[j]:=temp;
          inc(i);        dec(j);
        end;
    until i>j;
    if i<r then qsort(i,r);
    if l<j then qsort(l,j);
  end;

function min(a,b:longint):longint;
  begin  if  a<b  then  exit(a)  else  exit(b);  end;
function max(a,b:longint):longint;
  begin  if  a>b  then  exit(a)  else  exit(b);  end;

procedure main;
  var
    i,j:longint;
  begin
    readln(n,m);
    for i:=1 to n do  read   (a[i]);
    for i:=1 to m do
      begin
        readln (head[i],tail[i],rank[i]);
        queue[i]:=i;
      end;
    qsort(1,m);
    root:=0;
    p1:=head[1];  p2:=tail[1];
    for j:=p1 to p2 do  insert(root,a[j]);
    ans[queue[1]]:=select(root,rank[1]);
    for i:=2 to m do
      begin
        p1:=head[i-1];                  p2:=min(head[i]-1,tail[i-1]);
        for j:=p1 to p2 do  delete(root,a[j]);
        p1:=max(head[i],tail[i-1]+1);   p2:=tail[i];
        for j:=p1 to p2 do  insert(root,a[j]);
        ans[queue[i]]:=select(root,rank[i]);
      end;
    for i:=1 to m do  write(ans[i],' ');
  end;

begin
  main;
end.

