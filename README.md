# [:] BugHunt - :beetle::bomb:

## Description
This is a contest consisting of weekly challenges. Each challenge is some code with _one_ intentional bug. The goal is to find the bug. Simple! The bug may be a single line, or a contiguous section of code. This is a contest consisting of a new challenge every week. Each directory contains a different challenge. Please note, odious coding style or "unusual" design choices do not count as bugs. Forgive us.

Points are awarded by how quickly you solve the challenge. The maximum points for a challenge is 7. To get 7 points, your last submission must be correct and must have been submitted within 24 hours of the start of the challenge. For every 24 hour period after the start of the challenge, 1 point is deducted from the maximum. This means if you answer correctly on the last day, you get 1 point.

The first contest runs for 12 weeks.

## Submissions
Since we didn't want to spend all day processing submissions, we did what any good (read: _lazy_) developer would do and automated it. We built a Twitter bot. We named it ChallengeBot and it's connected to our Twitter account `@srcclr`. It processes submissions for us and does some other tedious stuff so we don't have to.

Briefly, the steps for submitting an answer to a challenge:

1. pick a challenge
2. find the bug
3. hash the *line number(s)* of the bug
4. submit hash to `@srcclr`

If the challenge is in progress, you'll have to wait until it's finished before we'll tell you if your answer is right. If the challenge is over, we will immediately tell you if the answer is right or wrong, but you won't get points for it.

Here's how each step works in detail:

### Step 1: Pick a Challenge
This part is easy. Each sub-directory is a challenge. The _name of the directory_ is the name of the challenge.

### Step 2: Find the Bug
The fun part. Just remember, the bug probably has some security implication, and bad style doesn't count as a bug.

### Step 3: Hash the Line Number(s)
Since Tweets are public, and we don't want people to steal each others answers, the answer must be hashed. This isn't enough to keep someone from brute forcing all hashes of line numbers, so you must append a secret, random "submission code" that we give you to your answer before hashing.

To request a submission code:

1. Follow `@srcclr`. This is so we can direct message you.
2. Tweet: `@srcclr send me my submission code`

Within a few seconds, you should get a reply with your unique submission code.

Once you have your submission code, append it to your answer and hash it, like this (but without brackets!):
```
echo -n "{answer}{submission code}" | openssl sha1
```

If you don't have access to a proper command line, you can use this: http://www.sha1-online.com/

If the answer is multiple lines, simply combine line numbers with commas.

Once you have your answer hash, submit it by Tweeting (without brackets!):
```
@srcclr submit {challenge name} {answer hash}
````

## Walkthrough with ExampleChallenge
The cleverly named [ExampleChallenge](ExampleChallenge) exists so you can make sure everything works. The answer for this challenge is `42`. Let's walk through how to submit a solution.

First, you'll need a submission code. Request it with `@srcclr send me my submission code`. Let's assume the submission code is `9b00047237880ae7048120cd90160604`.

Next, append your submission code to the answer to get `429b00047237880ae7048120cd90160604`.

Then, hash it using `echo -n "429b00047237880ae7048120cd90160604" | openssl sha1`.
The hash is `06770419e472bb356a90c1f7350baec981d0aa26`.

**Note:** when you do this for yourself, the submission code and the hash will be different!

Finally, submit the answer with `@srcclr submit ExampleChallenge 06770419e472bb356a90c1f7350baec981d0aa26`. You should get a reply telling you that your submission is correct.

## Disputes
We may unintentionally have more than the one bug in a challenge. We're only human (except ChallengeBot). If you get a challenge wrong, but believe you were right, please feel free to create a GitHub Issue. Explain to us why you think your answer is right. We'll review it and potentially add it as a correct answer. We may also review it and tell you something snarky like "LOL NOPE", indicating we disagree.

## Submitting Challenges
Check out our [Challenge Submission Guidelines](https://github.com/srcclr/bughunt/wiki/Challenge-Submission-Guidelines).

## Submitting Solutions
Check out our [Solution Write-Up Guidelines](https://github.com/srcclr/bughunt/wiki/Solution-Write-up-Guidelines).

## Contact
You can reach us via
[bughunt@srcclr.com](bughunt@srcclr.com).

# ChallengeBot Commands
ChallengeBot is open source. We hope dearly that the hordes of bug hunters we've attracted do not tear it to shreds. You can check it out here:
https://github.com/srcclr/challenge_bot
