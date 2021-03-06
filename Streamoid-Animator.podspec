Pod::Spec.new do |s|
  s.name = "Streamoid-Animator"
  s.version = "2.2.8"
  s.summary = "Animator is the iOS client interface for using exact search sdk provided by Streamoid"
  s.license = "MIT"
  s.authors = {"vengal"=>"vengal@streamoid.com", "naveen"=>"naveen@streamoid.com"}
  s.homepage = "http://streamoid.com/"
  s.requires_arc = true
  s.source = { git: 'https://github.com/streamoid/Animator-iOS.git', tag: "2.2.8" }
  s.ios.deployment_target    = '9.0'
  s.ios.vendored_framework   = 'Animator.framework'
end
