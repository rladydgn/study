import PostFragment from "@/components/PostFragment";
import samplePosts from "@/lib/constants/sample-posts.json"
import {notFound} from "next/navigation";

interface PageProps {
  params: Promise<{ postId: string }>;
}

// /feed 에서 Link 컴포넌트 사용해서 라우팅시 intercept 되어 보여지는 페이지
export default async function PostItemPage(props: PageProps) {
  const {params} = props;
  const {postId} = await params;

  const post = samplePosts.find((post) => post.id === postId);

  if (!post) {
    notFound();
  }

  return (
    <div className='box page'>
      <p>{`intercepted PostItemPage ${postId}`}</p>
      <PostFragment post={post}/>
    </div>
  );
}