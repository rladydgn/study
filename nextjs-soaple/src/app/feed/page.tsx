import {Suspense} from "react";
import {readPostsAction, readPostsActionWithCache, resetCache} from "@/lib/actions/posts";
import PostList from "@/components/PostList";

export default function FeedPage() {
  // const postsPromise = readPostsAction()
  const postsPromise = readPostsActionWithCache()

  return (
    <div className='box page'>
      <h4>Page</h4>
      <Suspense fallback={<div>Loading...</div>}>
        <PostList postsPromise={postsPromise}/>
      </Suspense>
      <button onClick={resetCache}>Reset Cache</button>
    </div>
  )
}
