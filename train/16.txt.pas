{For my love ZYM...}
var
v,lmax,rmax,maxv:array[1..1048575]of longint;
n,m,size,i,j,k,a,b:longint;

function getmax(a,b:longint):longint;

begin
  if a>b then
    getmax:=a
  else
    getmax:=b;
end;

procedure update(where,what:longint);

begin
  v[where]:=v[where]+what;
  lmax[where]:=v[where];
  rmax[where]:=v[where];
  maxv[where]:=v[where];
  where:=where shr 1;
  while where<>0 do
    begin
      v[where]:=v[where]+what;
      lmax[where]:=getmax(lmax[where shl 1],lmax[(where shl 1)+1]+v[where shl 1]);
      rmax[where]:=getmax(rmax[(where shl 1)+1],rmax[where shl 1]+v[(where shl 1)+1]);
      maxv[where]:=getmax(getmax(maxv[where shl 1],maxv[(where shl 1)+1]),rmax[where shl 1]+lmax[(where shl 1)+1]);
      where:=where shr 1;
    end;
end;

function maxr(where,l,r:longint):longint;

begin
  if a<=l then
    maxr:=rmax[where]
  else
    begin
      maxr:=maxr((where shl 1)+1,((l+r)shr 1)+1,r);
      if a<=(l+r)shr 1 then
        maxr:=getmax(maxr,maxr(where shl 1,l,(l+r)shr 1)+v[(where shl 1)+1]);
    end;
end;

function maxl(where,l,r:longint):longint;

begin
  if r<=b then
    maxl:=lmax[where]
  else
    begin
      maxl:=maxl(where shl 1,l,(l+r)shr 1);
      if (l+r)shr 1<b then
        maxl:=getmax(maxl,maxl((where shl 1)+1,((l+r)shr 1)+1,r)+v[where shl 1]);
    end;
end;

function max(where,l,r:longint):longint;

begin
  if (a<=l)and(r<=b) then
    max:=maxv[where]
  else
    begin
      max:=maxlongint+1;
      if a<=(l+r)shr 1 then
        max:=getmax(max,max(where shl 1,l,(l+r)shr 1));
      if (l+r)shr 1<b then
        max:=getmax(max,max((where shl 1)+1,((l+r)shr 1)+1,r));
      if(a<=(l+r)shr 1)and((l+r)shr 1<b)then
        max:=getmax(max,maxr(where shl 1,l,(l+r)shr 1)+maxl((where shl 1)+1,((l+r)shr 1)+1,r));
    end;
end;

begin
  readln(n,m);
  fillchar(v,sizeof(v),0);
  size:=1;
  while size<n do
    size:=size shl 1;
  for i:=1 to n-1 do
    begin
      read(v[size+i-1]);
      lmax[size+i-1]:=v[size+i-1];
      rmax[size+i-1]:=v[size+i-1];
      maxv[size+i-1]:=v[size+i-1];
    end;
  readln(v[size+n-1]);
  lmax[size+n-1]:=v[size+n-1];
  rmax[size+n-1]:=v[size+n-1];
  maxv[size+n-1]:=v[size+n-1];
  for i:=size-1 downto 1 do
    begin
      v[i]:=v[i shl 1]+v[(i shl 1)+1];
      lmax[i]:=getmax(lmax[i shl 1],lmax[(i shl 1)+1]+v[i shl 1]);
      rmax[i]:=getmax(rmax[(i shl 1)+1],rmax[i shl 1]+v[(i shl 1)+1]);
      maxv[i]:=getmax(getmax(maxv[i shl 1],maxv[(i shl 1)+1]),rmax[i shl 1]+lmax[(i shl 1)+1]);
    end;
  for i:=1 to m do
    begin
      readln(k,a,b);
      if k=1 then
        begin
          if a>b then
            begin
              a:=a xor b;
              b:=a xor b;
              a:=a xor b;
            end;
          write(max(1,1,size))
        end
      else
        update(size+a-1,b-v[size+a-1]);
    end;
end.
