import PostFragment from "@/components/PostFragment";

interface PageProps {
  params: Promise<{ postId: string }>;
}

// /feed 에서 Link 컴포넌트 사용해서 라우팅시 intercept 되어 보여지는 페이지
export default async function PostItemPage(props: PageProps) {
  const { params } = props;
  const { postId } = await params;

  return (
    <div className='box page'>
      <p>{`intercepted PostItemPage ${postId}`}</p>
      <PostFragment postId={postId} />
    </div>
  );
}